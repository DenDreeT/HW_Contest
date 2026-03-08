#ifndef MAIN_H
#define MAIN_H

#define OPTIONS_USAGE "Программа: area <OPTION>...\n"
#define OPTIONS_DESCRIPTION "Программа подсчета площади фигуры, образованной пересечением трех графиков финкций,\n\
поиск точек их пересечения,и отображения количества итераций поиска корней.\n\
 Поддерживает параметры командной строки для уточнения параметров и получения справки:\n"
#define OPTIONS_HELP "опции: -h, отображение справки.\n"
#define OPTIONS_Hh "  -h отображение справки.\n"
#define OPTIONS_i "  -i количество итераций, необходимых для поиска корней (совместно с <-r>)\n"
#define OPTIONS_a "  -a подсчет площади фигуры\n"
#define OPTIONS_r "  -r абсциссы точек пересечения кривых функций.\n"
#define OPTIONS_e "  -e ebs, точность нахождения корня.\n"
#define OPTIONS_E "  -E ebs, точность вычисления интеграла.\n"
#define OPTIONS_t "  -t тест функций вычисления корней и площади.\n"

#define OPTIONS_ERROR "ERROR: %s, ds, выберите ключ <-h> для справки.\n", argv[optind-1]
#endif
