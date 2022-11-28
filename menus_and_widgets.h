#ifndef MENUS_AND_WIDGETS_H_INCLUDED
#define MENUS_AND_WIDGETS_H_INCLUDED


void MainWndAddMenus(HWND hWnd) // main window menus
{
    HMENU RootMenu = CreateMenu();

    ComPortSubMenu = CreateMenu();
    ComPortListMenu = CreateMenu();
    GraphSubMenu = CreateMenu();

    AppendMenu(ComPortSubMenu, MF_STRING, OnConnectRequest, L"Connect"); // connect to port (submenu)
    AppendMenu(ComPortSubMenu, MF_SEPARATOR, 0, NULL); // separator
    AppendMenu(ComPortSubMenu, MF_STRING, OnSerialRefresh, L"Refresh ports"); // update list of ports (submenu)
    AppendMenu(ComPortSubMenu, MF_POPUP, (UINT_PTR)ComPortListMenu, L"Selected port"); // select port (submenu)

    AppendMenu(RootMenu, MF_POPUP, (UINT_PTR)ComPortSubMenu, L"Connection"); // main menu
    AppendMenu(RootMenu, MF_POPUP, (UINT_PTR)GraphSubMenu, L"Graphics"); // main menu
    AppendMenu(RootMenu, MF_STRING, (UINT_PTR)help, L"Help"); // main menu

    AppendMenu(GraphSubMenu, MF_STRING, (UINT_PTR)draw_plot, L"Draw plot");
    AppendMenu(GraphSubMenu, MF_STRING, (UINT_PTR)open_plot, L"Open plot");

    SetMenu(hWnd, RootMenu); // setting
}


void MainWndAddWidgets(HWND hWnd) // main window widgets
{
    RECT rc{};
    GetClientRect(hWnd, &rc);

    hStaticControl = CreateWindowA("static", "Welcome to the BMSD control app", WS_VISIBLE | WS_CHILD | ES_CENTER, 0, 10, 5, 20, hWnd, NULL, NULL, NULL); // welcome_text or COM port number
    hEditControl = CreateWindowA("edit", "", WS_VISIBLE | WS_CHILD | ES_CENTER | WS_BORDER | ES_MULTILINE | WS_VSCROLL, 40, 70+10, 420, 150, hWnd, NULL, NULL, NULL); // text from file (time & speed)

    open_file_but =  CreateWindow(L"button", L"Open file", WS_VISIBLE | WS_CHILD | ES_CENTER | WS_BORDER | BS_PUSHBUTTON, 20, 25+10, 200, 40, hWnd, (HMENU)open_file, NULL, NULL); // open file
    send_but =  CreateWindow(L"button", L"Send commands", WS_VISIBLE | ES_CENTER | WS_CHILD | WS_BORDER | BS_PUSHBUTTON, 260, 25+10, 200, 40, hWnd, (HMENU)send_commands, NULL, NULL); // send commands from file
    emergency_stop_but = CreateWindow(L"button", L"STOP turntable", WS_VISIBLE | WS_BORDER | WS_CHILD | ES_CENTER | BS_PUSHBUTTON, 0, 225+10, rc.right, 50, hWnd, (HMENU)emergency_stop_button, NULL, NULL); // stop button
}


void GraphicsWidgets(HWND hWnd)
{
    RECT rc{};
    GetClientRect(hWnd, &rc);

    open_file_gr_but =  CreateWindow(L"button", L"Open file", WS_VISIBLE | WS_CHILD | ES_CENTER | WS_BORDER | BS_PUSHBUTTON, 0, 0, 200, 40, hWnd, (HMENU)open_file_gr, NULL, NULL); // open file
    hEditPoints = CreateWindowA("edit", "", WS_VISIBLE | WS_CHILD | ES_CENTER | WS_BORDER | ES_MULTILINE | WS_VSCROLL, 40, 70+10, 420, 150, hWnd, NULL, NULL, NULL); // text from file (time & speed)
    flip_plot_but =  CreateWindow(L"button", L"Vertical flip", WS_VISIBLE | WS_CHILD | ES_CENTER | WS_BORDER | BS_PUSHBUTTON, 0, 0, 200, 40, hWnd, NULL, NULL, NULL);
}


void HelpWidgets(HWND hWnd)
{
    RECT rc{};
    GetClientRect(hWnd, &rc);

    title =  CreateWindowA("static", "Application guide",  WS_VISIBLE | WS_CHILD | ES_CENTER, 0, 10, 5, 20, hWnd, NULL, NULL, NULL); // title
    connection_text_0 = CreateWindowA("static", "CONNECTION TO PORT",  WS_VISIBLE | WS_CHILD | ES_LEFT, 0, 10, 5, 20, hWnd, NULL, NULL, NULL);
    connection_text_1 = CreateWindowA("static", "1. Connect port to PC and check if it is in SELECTED PORT menu. If no: refresh list of ports, then press CONNECT",  WS_VISIBLE | WS_CHILD | ES_LEFT, 0, 10, 5, 20, hWnd, NULL, NULL, NULL);
    start_rotation_0 = CreateWindowA("static", "2. Select data file (time,sec ang_velocity,deg/sec). Send commands to turntable. For emergency stop press STOP TURNTABLE button",  WS_VISIBLE | WS_CHILD | ES_LEFT, 0, 10, 5, 20, hWnd, NULL, NULL, NULL); // title
    graphics_text_0 = CreateWindowA("static", "GRAPHICS",  WS_VISIBLE | WS_CHILD | ES_LEFT, 0, 30, 5, 20, hWnd, NULL, NULL, NULL);
    draw_text_0 = CreateWindowA("static", "DRAW PLOT",  WS_VISIBLE | WS_CHILD | ES_LEFT, 0, 30, 5, 20, hWnd, NULL, NULL, NULL);
    open_text_0 = CreateWindowA("static", "OPEN PLOT",  WS_VISIBLE | WS_CHILD | ES_LEFT, 0, 30, 5, 20, hWnd, NULL, NULL, NULL);
    open_text_1 = CreateWindowA("static", "The screen is divided into two parts: the plot is built on the left side, the controls are on the right",  WS_VISIBLE | WS_CHILD | ES_LEFT, 0, 30, 5, 20, hWnd, NULL, NULL, NULL);
    open_text_2 = CreateWindowA("static", "1. At the beginning, you select data file in the same format as when you started the turntable. The plot and grid are displayed. Grid step is determined from data file", WS_VISIBLE | WS_CHILD | ES_LEFT, 0, 30, 5, 20, hWnd, NULL, NULL, NULL);
    open_text_3 = CreateWindowA("static", "2. To flip plot around the horizontal axis press VERTICAL FLIP", WS_VISIBLE | WS_CHILD | ES_LEFT, 0, 30, 5, 20, hWnd, NULL, NULL, NULL);

}
#endif // MENUS_AND_WIDGETS_H_INCLUDED
