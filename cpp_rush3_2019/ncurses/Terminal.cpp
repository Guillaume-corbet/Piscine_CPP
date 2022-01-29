/*
** EPITECH PROJECT, 2020
** rush3
** File description:
** Terminal
*/

#include "Terminal.hpp"

Terminal::Terminal(int cols, int lines)
{
    this->_cols = cols;
    this->_lines = lines;
    this->time = std::time(nullptr);
}

Terminal::~Terminal()
{
}

int Terminal::getCols() const
{
    return (this->_cols);
}

int Terminal::getLines() const
{
    return (this->_lines);
}

void Terminal::setCols(int cols)
{
    this->_cols = cols;
}

void Terminal::setLines(int lines)
{
    this->_lines = lines;
}

void Terminal::terminalSizeChange()
{
    if (this->getCols() != COLS || this->getLines() != LINES) {
        this->setCols(COLS);
        this->setLines(LINES);
        clear();
        refresh();
    }
}

int Terminal::terminalTooSmall(void)
{
    int ch;

    if (LINES < 50 || COLS < 130) {
        clear();
    }
    while (LINES < 50 || COLS < 130) {
        this->terminalSizeChange();
        mvprintw(LINES / 2, COLS / 2 - 10, "Terminal too small");
        ch = getch();
        if (ch == 'q')
            return (42);
    }
    return (0);
}

int Terminal::pauseMenu(void)
{
    int ch = getch();

    clear();
    while (ch != 'p') {
        this->terminalSizeChange();
        mvprintw(LINES / 2, COLS / 2 - 14, "PAUSE press again to continue");
        ch = getch();
        if (ch == 'q')
            return (42);
    }
    clear();
    return (0);
}

void Terminal::printHtop(void)
{

    mvprintw(0, COLS / 2 - 25,"...");
    mvprintw(1, COLS / 2 - 25, "dMMO           'oo;");
    mvprintw(2, COLS / 2 - 25, "dMMO           'oo;");
    mvprintw(3, COLS / 2 - 25, "dMMk .'.     ..xMMK'...      .''.      ... ..'.");
    mvprintw(4, COLS / 2 - 25, "dMMNXWMMNo  kMMMMMMMMM0   ,OWMMMMNd.  .NMMNWMMMXd");
    mvprintw(5, COLS / 2 - 25, "dMMK'.oMMM' ...xMMK,...  ;WMX:..oMMX' 'WMMO'.cNMMl");
    mvprintw(6, COLS / 2 - 25, "dMMk  ,MMM'    oMM0      dMMk    OMMx 'WMMl   0MMO");
    mvprintw(7, COLS / 2 - 25, "dMMO  ,MMM'    oMMK.     lMM0.  .XMMl 'WMMd   KMMx");
    mvprintw(8, COLS / 2 - 25, "dMMO  ;MMM'    ;WMWKOOo  .dNMXxxXMXl  'WMMW0xKMMK.");
    mvprintw(9, COLS / 2 - 25, "'ll,  .lll.     .;clll;    .;lllc,    'WMMx:llc,");
    mvprintw(10, COLS / 2 - 25, "                                      'WMMl");
    mvprintw(11, COLS / 2 - 25, "                                      .NMMl");
            
}

void Terminal::printComputer(void)
{
    mvprintw(0, 0, "                __");
    mvprintw(1, 0, "    ..======.. |==|");
    mvprintw(2, 0, "    ||      || |= |");
    mvprintw(3, 0, " _  ||      || |^*| _");
    mvprintw(4, 0, "|=| o=,====,=o |__||=|");
    mvprintw(5, 0, "|_|  _______)    ) |_|");
    mvprintw(6, 0, "    [========]  ()");
    mvprintw(7, 0, " MY BELOVED COMPUTER");
}

void Terminal::printChangeMode(char change)
{
    std::string str;
    char c[2];

    c[0] = change;
    c[1] = '\0';
    
    str = "Press ";
    str.append(c);
    str.append(" to go graphic mode");
    mvprintw(LINES - 1, COLS / 2 - 15, str.c_str());
}

void Terminal::printHeader(char change)
{
    this->printComputer();
    this->printHtop();
    this->printChangeMode(change);
}

void Terminal::printUbuntu(void)
{
    mvprintw(LINES / 2 - 19 + 0, COLS / 2 - 39, "                         nK0kxddooooodxk0Kn");
    mvprintw(LINES / 2 - 19 + 1, COLS / 2 - 39, "                    NKOxolllllllllllllllllloxO0N");
    mvprintw(LINES / 2 - 19 + 2, COLS / 2 - 39, "                N0xollllllllllllllllllllllllllllox0X");
    mvprintw(LINES / 2 - 19 + 3, COLS / 2 - 39, "             XOollllllllllllllllllllllllllllllllllllokX");
    mvprintw(LINES / 2 - 19 + 4, COLS / 2 - 39, "          W0dlllllllllllllllllllllllllllllllllllllllllld0W");
    mvprintw(LINES / 2 - 19 + 5, COLS / 2 - 39, "        WOollllllllllllllllllllllllllllllloxkkxollllllllloOW");
    mvprintw(LINES / 2 - 19 + 6, COLS / 2 - 39, "       KollllllllllllllllllllllllllllllllOWMMMMM0lllllllllloK");
    mvprintw(LINES / 2 - 19 + 7, COLS / 2 - 39, "     NkllllllllllllllllllllllllooddoolllxMMMMMMMMxlllllllllllxN");
    mvprintw(LINES / 2 - 19 + 8, COLS / 2 - 39, "    KollllllllllllllllllloO0XNWMMMMMMWNdoNMMMMMMNolllllllllllloK");
    mvprintw(LINES / 2 - 19 + 9, COLS / 2 - 39, "   0lllllllllllllllllldlll0MMMMMMMMMMMMNxoOXNNXOolllllllllllllll0");
    mvprintw(LINES / 2 - 19 + 10, COLS / 2 - 39, "  KlllllllllllllllllkNMMlllOWMMMWWWWMMMMMN0kkkkklllllllllllllllllK");
    mvprintw(LINES / 2 - 19 + 11, COLS / 2 - 39, " WollllllllllllllldXMMMMMlllxkdollllodk0NMMMMMMMNdllllllllllllllloN");
    mvprintw(LINES / 2 - 19 + 12, COLS / 2 - 39, " klllllllllllllllkWMMMMMM0llllllllllllllld0WMMMMMWklllllllllllllllk");
    mvprintw(LINES / 2 - 19 + 13, COLS / 2 - 39,"XlllllllllllllllkMMMMMMXdlllllllllllllllllldXMMMMMMklllllllllllllllX");
    mvprintw(LINES / 2 - 19 + 14, COLS / 2 - 39,"OllllllllllddollNMMMMMKllllllllllllllllllllllKMMMMMWdllllllllllllllk");
    mvprintw(LINES / 2 - 19 + 15, COLS / 2 - 39,"dlllllllxXWMMMXxoKMMMNolllllllllllllllllllllloNMMMMM0lllllllllllllld");
    mvprintw(LINES / 2 - 19 + 16, COLS / 2 - 39,"olllllldWMMMMMMMxlNMM0lllllllllllllllllllllllloNMMMNxllllllllllllllo");
    mvprintw(LINES / 2 - 19 + 17, COLS / 2 - 39,"olllllloWMMMMMMWxlNMM0lllllllllllllllllllllllllllllllllllllllllllllo");
    mvprintw(LINES / 2 - 19 + 18, COLS / 2 - 39,"xllllllldKWMMWKdoKMMMWolllllllllllllllllllllloNMMMMM0lllllllllllllld");
    mvprintw(LINES / 2 - 19 + 19, COLS / 2 - 39,"OlllllllllloolllNMMMMMXllllllllllllllllllllllKMMMMMWdllllllllllllllk");
    mvprintw(LINES / 2 - 19 + 20, COLS / 2 - 39,"NlllllllllllllllxWMMMMMNxlllllllllllllllllldXMMMMMWklllllllllllllllX");
    mvprintw(LINES / 2 - 19 + 21, COLS / 2 - 39," OlllllllllllllllxNMMMMMMKdllllllllllllllxKMMMMMMWxlllllllllllllllk");
    mvprintw(LINES / 2 - 19 + 22, COLS / 2 - 39," WdllllllllllllllloKMMMMMNlllOxdollodxOKWMMMMMMMXollllllllllllllloW");
    mvprintw(LINES / 2 - 19 + 23, COLS / 2 - 39,"  XlllllllllllllllllxXMMNlllMMMMMWWMMMMMMXOxxxxxlllllllllllllllllK");
    mvprintw(LINES / 2 - 19 + 24, COLS / 2 - 39,"   KlllllllllllllllllldklllMMMMMMMMMMMMNdo0NWWN0olllllllllllllllK");
    mvprintw(LINES / 2 - 19 + 25, COLS / 2 - 39,"    XollllllllllllllllllllkOKXNWMMMMWNXdoNMMMMMMWolllllllllllloX");
    mvprintw(LINES / 2 - 19 + 26, COLS / 2 - 39,"     WklllllllllllllllllllllllllloolllllxMMMMMMMMxlllllllllllkW");
    mvprintw(LINES / 2 - 19 + 27, COLS / 2 - 39,"       XdllllllllllllllllllllllllllllllllkNMMMMWOlllllllllldX");
    mvprintw(LINES / 2 - 19 + 28, COLS / 2 - 39,"        W0dlllllllllllllllllllllllllllllllldxxdllllllllllo0W");
    mvprintw(LINES / 2 - 19 + 29, COLS / 2 - 39,"           KxllllllllllllllllllllllllllllllllllllllllllxK");
    mvprintw(LINES / 2 - 19 + 30, COLS / 2 - 39,"             N0dlllllllllllllllllllllllllllllllllllldON");
    mvprintw(LINES / 2 - 19 + 31, COLS / 2 - 39,"                NKkdlllllllllllllllllllllllllllldkKN");
    mvprintw(LINES / 2 - 19 + 32, COLS / 2 - 39,"                    WX0kdollllllllllllllllodk0KW");
    mvprintw(LINES / 2 - 19 + 33, COLS / 2 - 39,"                          WXKOkddooooddxO0");

}

void Terminal::printName(void)
{
    mvprintw(LINES / 2 - 19 + 35, COLS / 2 - 39, "                          Maxime Barbier");
    mvprintw(LINES / 2 - 19 + 36, COLS / 2 - 39, "                          Samuel Parayre");
    mvprintw(LINES / 2 - 19 + 37, COLS / 2 - 39, "                           Amel Djellal");
    mvprintw(LINES / 2 - 19 + 38, COLS / 2 - 39, "                         Guillaume Corbet");
}

void Terminal::printEnd(void)
{
    std::time_t time = std::time(nullptr);
    std::time_t newTime = std::time(nullptr);

    clear();
    while (time + 3 > newTime) {
        this->terminalSizeChange();
        this->printUbuntu();
        this->printName();
        refresh();
        newTime = std::time(nullptr);
    }
}

void Terminal::printBox(void)
{
    int i = 14;
    int j = 0;
    std::string first = "+";

    while (j < COLS - 6) {
        if (j - 1 == COLS / 2 - 4)
            first.append("+");
        else
            first.append("-");
        j = j + 1;
    }
    first.append("+");
    j = 0;
    mvprintw(13, 2, first.c_str());
    while (i < LINES - 3) {
        mvprintw(i, 2, "|");
        mvprintw(i, COLS - 3, "|");
        i = i + 1;
    }
    mvprintw(i, 2, first.c_str());
}

void Terminal::printLine(void)
{
    int j = 0;
    std::string first = "+";
    std::string second = "+";
    int lenght = LINES - 17;

    while (j < COLS - 6) {
        if (j < COLS / 2 - 4) {
            second.append("-");
        }
        if (j - 1 == COLS / 2 - 4)
            first.append("+");
        else
            first.append("-");
        j = j + 1;
    }
    first.append("+");
    second.append("+");
    mvprintw(lenght / 3 + 13, COLS / 2, second.c_str());
    mvprintw((lenght / 3) * 2 + 14, 2, first.c_str());
}

void Terminal::printMiddle(void)
{
    int j = 0;
    int lenght = 14;
    int i = COLS / 2;

    while (lenght < LINES - 3) {
        mvprintw(lenght, i, "|");
        lenght = lenght + 1;
    }
}

void Terminal::printRam(Ram *ram)
{
    int len = (LINES - 17) / 3 + 13 + 2;
    std::string str;
    
    mvprintw(len, COLS / 2 + 2, "RAM");
    len = len + 1;
    str = "-> Ram Total = " + std::to_string(ram->getRamTotal()) + " KB";
    mvprintw(len, COLS / 2 + 2, str.c_str());
    if (ram->getRamUsed() < ram->getRamTotal() / 2) {
        attron(COLOR_PAIR(2));
    } else if (ram->getRamUsed() > ram->getRamTotal() / 1.5) {
        attron(COLOR_PAIR(3));
    } else {
        attron(COLOR_PAIR(1));
    }
    str = "-> Ram Used = " + std::to_string(ram->getRamUsed()) + " KB";
    mvprintw(len + 1, COLS / 2 + 2, str.c_str());
    if (ram->getRamUsed() < ram->getRamTotal() / 2) {
        attroff(COLOR_PAIR(2));
    } else if (ram->getRamUsed() > ram->getRamTotal() / 1.5) {
        attroff(COLOR_PAIR(3));
    } else {
        attroff(COLOR_PAIR(1));
    }
    str = "-> Ram Free = " + std::to_string(ram->getRamFree()) + " KB";
    if (ram->getRamFree() < ram->getRamTotal() / 2 && ram->getRamFree() > ram->getRamTotal() / 4) {
        attron(COLOR_PAIR(1));
    } else if (ram->getRamFree() > ram->getRamTotal() / 2) {
        attron(COLOR_PAIR(2));
    } else {
        attron(COLOR_PAIR(3));
    }
    mvprintw(len + 2, COLS / 2 + 2, str.c_str());
    if (ram->getSwapUsed() < ram->getSwapTotal() / 2 && ram->getSwapFree() > ram->getSwapTotal() / 4) {
        attroff(COLOR_PAIR(1));
    } else if (ram->getSwapUsed() > ram->getSwapTotal() / 2) {
        attroff(COLOR_PAIR(2));
    } else {
        attroff(COLOR_PAIR(3));
    }
    str = "-> Swap Total = " + std::to_string(ram->getSwapTotal()) + " KB";
    mvprintw(len + 3, COLS / 2 + 2, str.c_str());
    if (ram->getSwapUsed() < ram->getSwapTotal() / 2) {
        attron(COLOR_PAIR(2));
    } else if (ram->getSwapUsed() > ram->getSwapTotal() / 1.5) {
        attron(COLOR_PAIR(3));
    } else {
        attron(COLOR_PAIR(1));
    }
    str = "-> Swap Used = " + std::to_string(ram->getSwapUsed()) + " KB";
    mvprintw(len + 4, COLS / 2 + 2, str.c_str());
    if (ram->getSwapUsed() < ram->getSwapTotal() / 2) {
        attroff(COLOR_PAIR(2));
    } else if (ram->getSwapUsed() > ram->getSwapTotal() / 1.5) {
        attroff(COLOR_PAIR(3));
    } else {
        attroff(COLOR_PAIR(1));
    }
    str = "-> Swap Free = " + std::to_string(ram->getSwapFree()) + " KB";
    if (ram->getSwapFree() < ram->getSwapTotal() / 2 && ram->getSwapFree() > ram->getSwapTotal() / 4) {
        attron(COLOR_PAIR(1));
    } else if (ram->getSwapFree() > ram->getSwapTotal() / 2) {
        attron(COLOR_PAIR(2));
    } else {
        attron(COLOR_PAIR(3));
    }
    mvprintw(len + 5, COLS / 2 + 2, str.c_str());
    if (ram->getSwapUsed() < ram->getSwapTotal() / 2 && ram->getSwapFree() > ram->getSwapTotal() / 4) {
        attroff(COLOR_PAIR(1));
    } else if (ram->getSwapUsed() > ram->getSwapTotal() / 2) {
        attroff(COLOR_PAIR(2));
    } else {
        attroff(COLOR_PAIR(3));
    }
}

void Terminal::printComputer(Processor *processor, Monitor *monitor)
{
    std::string str;


    mvprintw(15, 4, "Monitor");
    str = "-> SysName : " + monitor->getSysName();
    mvprintw(16, 4 , str.c_str());
    str = "-> UserName : " + monitor->getUserName();
    mvprintw(17, 4, str.c_str());
    str = "-> HostName : " + monitor->getHostName();
    mvprintw(18, 4, str.c_str());
    str = "-> Operating system : " + monitor->getOperatingSystem();
    mvprintw(19, 4, str.c_str());
    str = "-> Kernel version : " + monitor->getKernelVersion();
    mvprintw(20, 4, str.c_str());
    str = "-> Date : " + monitor->getDate();
    mvprintw(21, 4, str.c_str());
    str = "-> Model name : " + processor->getModelName();
    mvprintw(22, 4, str.c_str());
    str = "-> Architecture : " + processor->getArchitecture();
    mvprintw(23, 4, str.c_str());
}

void Terminal::printProcessor(Processor *processor)
{
    std::string str;

    mvprintw(15, COLS / 2 + 2, "CPU");
    str = "-> Usage = " + std::to_string(processor->getUsage()) + "%";
    if (processor->getUsage() < 50) {
        attron(COLOR_PAIR(2));
    } else if (processor->getUsage() > 50 && processor->getUsage() < 75) {
        attron(COLOR_PAIR(1));
    } else {
        attron(COLOR_PAIR(3));
    }
    mvprintw(16, COLS / 2 + 2, str.c_str());
    if (processor->getUsage() < 50) {
        attroff(COLOR_PAIR(2));
    } else if (processor->getUsage() > 50 && processor->getUsage() < 75) {
        attroff(COLOR_PAIR(1));
    } else {
        attroff(COLOR_PAIR(3));
    }
    str = "-> Speed = " + std::to_string(processor->getSpeed()) + " MHz";
    mvprintw(17, COLS / 2 + 2, str.c_str());
    str = "-> Speed min = " + std::to_string(processor->getVMin()) + " MHz";
    mvprintw(18, COLS / 2 + 2, str.c_str());
    str = "-> Speed max = " + std::to_string(processor->getVMax()) + " MHz";
    mvprintw(19, COLS / 2 + 2, str.c_str());
    str = "-> Number cores = " + std::to_string(processor->getNbCores());
    mvprintw(20, COLS / 2 + 2, str.c_str());
    str = "-> Number threads = " + std::to_string(processor->getNbCores() * processor->getNbThreads());
    mvprintw(21, COLS / 2 + 2, str.c_str());
}

void Terminal::printNetwork(Network *network)
{
    std::string str;
    int len = (LINES - 17) / 3 * 2 + 13 + 3;

    mvprintw(len, COLS / 2 + 2, "TEST");
}

void Terminal::printMainScreen(Data *data, char change)
{
    this->printHeader(change);
    this->printBox();
    this->printMiddle();
    this->printLine();
    if (data->getRam()->isDisplay())
        this->printRam(data->getRam());
    if (data->getMonitor()->isDisplay())
        this->printComputer(data->getProcessor(), data->getMonitor());
    if (data->getProcessor()->isDisplay())
        this->printProcessor(data->getProcessor());
    if (data->getNetwork()->isDisplay())
        this->printNetwork(data->getNetwork());
}

std::time_t Terminal::getTime() const
{
    return (this->time);
}

void Terminal::setTime(std::time_t time)
{
    this->time = time;
}