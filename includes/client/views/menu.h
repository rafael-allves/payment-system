#ifndef VIEW_MENU_H
#define VIEW_MENU_H

void changeScreenLogin()
{
    
}


void changeScreenRegister()
{
    
}

void renderMenu()
{    
    Box *window = initScreen(1);

    unsigned short *windowCenter = getCenterPos(window, 10, TRUE, TRUE);
    
    Box *title = createBox(10, 5, windowCenter[0] + 3, 3);
    createBorder(title, 1, "-");
    unsigned short *titleTextPos = getCenterPos(title, 4, TRUE, TRUE);
    renderText(titleTextPos[0], titleTextPos[1], "MENU");

    Button *Entrar = createButton(15, 5, windowCenter[0], windowCenter[1], " Entrar", changeScreenLogin);
    Button *Cadastrar = createButton(15, 5, windowCenter[0], (windowCenter[1] + Entrar->height + 2), "Cadastrar", changeScreenRegister);

    free(window); free(title); free(titleTextPos); free(windowCenter);
}

#endif