#ifndef HELP_H_INCLUDED
#define HELP_H_INCLUDED

LRESULT CALLBACK HELPProc(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp)
{
    switch (msg)
    {
    case WM_CREATE:
        HelpWidgets(hWnd);
    case WM_SIZE:
        RECT rc;
        GetClientRect(hWnd, &rc);
        SetWindowPos(title, NULL, 0, 10, rc.right, 20, SWP_NOZORDER);

        SetWindowPos(connection_text_0, NULL, rc.right/10 - rc.right/15, 40, rc.right/4, 20, SWP_NOZORDER);
        SetWindowPos(connection_text_1, NULL, rc.right/10, 70, rc.right, 40, SWP_NOZORDER);
        SetWindowPos(start_rotation_0, NULL, rc.right/10, 100, rc.right, 40, SWP_NOZORDER);

        SetWindowPos(graphics_text_0, NULL, rc.right/10 - rc.right/15, 150, rc.right/4, 20, SWP_NOZORDER);
        SetWindowPos(draw_text_0, NULL, rc.right/10 - rc.right/25, 180, rc.right/4, 20, SWP_NOZORDER);
        SetWindowPos(open_text_0, NULL, rc.right/10 - rc.right/25, 200, rc.right/4, 20, SWP_NOZORDER);
        SetWindowPos(open_text_1, NULL, rc.right/10, 220, rc.right, 40, SWP_NOZORDER);
        SetWindowPos(open_text_2, NULL, rc.right/10, 250, rc.right, 40, SWP_NOZORDER);
        SetWindowPos(open_text_3, NULL, rc.right/10, 270, rc.right, 40, SWP_NOZORDER);
    }
    return DefWindowProc(hWnd, msg, wp, lp);
}

#endif // HELP_H_INCLUDED
