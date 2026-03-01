#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <ncurses.h>
#include <time.h>
#include <unistd.h>

#define MIN_Y 2
#define CONTROLS 3

// Константы
enum {
    LEFT = 1,
    UP,
    RIGHT,
    DOWN,
    STOP_GAME = KEY_F(10)
};

enum {
    MAX_TAIL_SIZE = 100,
    START_TAIL_SIZE = 10,
    MAX_FOOD_SIZE = 20,
    FOOD_EXPIRE_SECONDS = 10
};

// Код управления змейкой
struct control_buttons {
    int down;
    int up;
    int left;
    int right;
};

// в массив кодов управления добавлены два новых элемента - клавиши WSAD и wsad
struct control_buttons default_controls[CONTROLS] = {{KEY_DOWN, KEY_UP, KEY_LEFT, KEY_RIGHT}, {'S', 'W', 'A', 'D'}, {'s', 'w', 'a', 'd'}};

// структура змейки
typedef struct snake_t {
    int x;
    int y;
    int direction;
    size_t tsize;
    struct tail_t* tail;
    struct control_buttons* controls;
} snake_t;

// структура хвоста
typedef struct tail_t {
    int x;
    int y;
} tail_t;

// структура еды
typedef struct food {
    int x;
    int y;
    time_t put_time;
    char point;
    uint8_t enable;
} food[MAX_FOOD_SIZE];

// инициализация хвоста
void initTail(tail_t t[], size_t size) {
    tail_t init_t = {0, 0};
    for (size_t i = 0; i < size; i++)
        t[i] = init_t;
}

// инициализация головы
void initHead(snake_t* head, int x, int y) {
    head -> x = x;
    head -> y = y;
    head -> direction = RIGHT;
}

// инициализация всей змейки
void initSnake(snake_t* head, size_t size, int x, int y) {
    tail_t* tail = (tail_t*) malloc(MAX_TAIL_SIZE * sizeof(tail_t));
    initTail(tail, MAX_TAIL_SIZE);
    initHead(head, x, y);
    head -> tail = tail;
    head -> tsize = size + 1;
    head -> controls = default_controls;
}

// движение головы
void go(snake_t* head) {
    char ch = '@';
    int max_x = 0, max_y = 0;
    getmaxyx(stdscr, max_y, max_x);
    mvprintw(head -> y, head -> x, " ");
    switch (head -> direction) {
        case LEFT:
            if (head -> x <= 0)
                head -> x = max_x; // выход за левую границу
            mvprintw(head -> y, --(head -> x), "%c", ch);
            break;
        case RIGHT:
            if (head -> x >= max_x)
                head -> x = 0; // выход за правую границу
            mvprintw(head -> y, ++(head -> x), "%c", ch);
            break;
        case UP:
            if (head -> y <= MIN_Y)
                head -> y = max_y; // выход за верхнюю границу
            mvprintw(--(head -> y), head -> x, "%c", ch);
            break;
        case DOWN:
            if (head -> y >= max_y)
                head -> y = MIN_Y; // выход за нижнюю границу
            mvprintw(++(head -> y), head -> x, "%c", ch);
            break;
        default:
            break;
    }
    refresh();
}

// движение хвоста
void goTail(snake_t* head) {
    char ch = '*';
    mvprintw(head -> tail[head -> tsize - 1].y,head -> tail[head -> tsize - 1].x, " ");
    for (size_t i = head -> tsize - 1; i > 0; i--) {
        head -> tail[i] = head -> tail[i - 1];
        if ((head -> tail[i].y) || (head -> tail[i].x))
            mvprintw(head -> tail[i].y, head -> tail[i].x, "%c", ch);
    }
    head -> tail[0].x = head -> x;
    head -> tail[0].y = head -> y;
}

// проверка на корректность управлением змейкой игроком 
// (блокировка нажатия клавиш, противоположных движению)
int checkDirection(snake_t* snake, int32_t key) {
    for (int i = 0; i < CONTROLS; i++) {    
        if ((key == snake -> controls[i].down && snake -> direction == UP) || // запрет на перемещение сверху вниз
        (key == snake -> controls[i].up && snake -> direction == DOWN) ||     // запрет на перемещение снизу вверх
        (key == snake -> controls[i].left && snake -> direction == RIGHT) ||  // запрет на перемещение справа налево
        (key == snake -> controls[i].right && snake -> direction == LEFT))    // запрет на перемещение слева направо
            return 0;
    }
    return 1;
}

// смена направления движения
void changeDirection(snake_t* snake, const int32_t key) {
    if (!checkDirection(snake, key))
        return;

    for (int i = 0; i < CONTROLS; i++) {
        if (key == snake -> controls[i].down)
            snake -> direction = DOWN;
        else if (key == snake -> controls[i].up)
            snake -> direction = UP;
        else if (key == snake -> controls[i].right)
            snake -> direction = RIGHT;
        else if (key == snake -> controls[i].left)
            snake -> direction = LEFT;
    }
}

// проверка, не врезалась ли змейка сама в себя
_Bool isCrush(snake_t* snake) {
    for (size_t i = 1; i < snake->tsize; i++) {
        if (snake->x == snake->tail[i].x && snake->y == snake->tail[i].y)
            return 1;
    }
    return 0;
}

// печать сообщения об аварии
void printCrush() {
    int max_x = 0, max_y = 0;
    getmaxyx(stdscr, max_y, max_x);
    mvprintw(max_y / 2 - 1, max_x / 2 - 5, "Crash!");
    refresh();
    getchar();
}

// инициализация еды
void initFood(struct food f[], size_t size) {
    struct food init = {0, 0, 0, 0, 0};
    int max_y = 0, max_x = 0;
    getmaxyx(stdscr, max_y, max_x);
    for(size_t i = 0; i < size; i++)
        f[i] = init;
}

// размещение еды на игровом поле
void putFoodSeed(struct food* fp) {
    int max_x = 0, max_y = 0;
    char spoint[2] = {0};
    getmaxyx(stdscr, max_y, max_x);
    mvprintw(fp->y, fp->x, " ");
    fp->x = rand() % (max_x - 1);
    fp->y = rand() % (max_y - 2) + 2;
    fp->put_time = time(NULL);
    fp->point = '$';
    fp->enable = 1;
    spoint[0] = fp -> point;
    mvprintw(fp->y, fp->x, "%s", spoint);
}

void putFood(struct food f[], size_t number_seeds) {
    for(size_t i = 0; i < number_seeds; i++)
        putFoodSeed(&f[i]);
}

// обновление еды
void refreshFood(struct food f[], int nfood) {
    int max_x = 0, max_y = 0;
    //char
    getmaxyx(stdscr, max_y, max_x);
    for(size_t i = 0; i < nfood; i++) {
        if(f[i].put_time) {
            if(!f[i].enable || (time(NULL) - f[i].put_time) > FOOD_EXPIRE_SECONDS)
                putFoodSeed(&f[i]);
        }
    }
}


int main(void) {
    snake_t* snake = (snake_t*)malloc(sizeof(snake_t));
    struct food food[MAX_FOOD_SIZE];

    initSnake(snake, START_TAIL_SIZE, 10, 10);
    initFood(food, MAX_FOOD_SIZE);

    initscr();
    keypad(stdscr, TRUE);
    raw();
    noecho();
    curs_set(FALSE);
    mvprintw(0, 1, "Use arrows or WASD keys for control. Press 'F10' for EXIT.");
    timeout(0);
    int key_pressed = 0;

    putFoodSeed(food);
    putFood(food, MAX_FOOD_SIZE);

    while (key_pressed != STOP_GAME) {
        key_pressed = getch();
        if (isCrush(snake)) {
            printCrush(); // сообщение об аварии, если змейка врезалась сама в себя
            break;        // выход из программы
        }
        go(snake);
        goTail(snake);
        timeout(100);
        changeDirection(snake, key_pressed);
    }
    
    free(snake -> tail);
    free(snake);
    endwin();
    return 0;
}
