#include<graphics.h>
#include<stdio.h>
//�������ݽṹ
char chboard_date [3][3] =
{
    {'_','_','_'},
    {'_','_','_'},
    {'_','_','_'},
};

//��ʶ��ǰ��������
char current_piece ='O';

//���ָ����������Ƿ��ʤ
bool Checkwin(char c)
{
    if (chboard_date[0][0] == c && chboard_date[1][1] == c && chboard_date[2][2] == c)
        return true;
    if (chboard_date[0][0] == c && chboard_date[0][1] == c && chboard_date[0][2] == c)
        return true;
    if (chboard_date[0][0] == c && chboard_date[1][0] == c && chboard_date[2][0] == c)
        return true;
    if (chboard_date[0][1] == c && chboard_date[1][1] == c && chboard_date[2][1] == c)
        return true;
    if (chboard_date[0][2] == c && chboard_date[1][2] == c && chboard_date[2][2] == c)
        return true;
    if (chboard_date[0][2] == c && chboard_date[1][1] == c && chboard_date[2][0] == c)
        return true;
    if (chboard_date[1][0] == c && chboard_date[1][1] == c && chboard_date[1][2] == c)
        return true;
    if (chboard_date[2][0] == c && chboard_date[2][1] == c && chboard_date[2][2] == c)
        return true;
    return false;
}

//����Ƿ�ƽ��
bool CheckDraw()
{
    for (size_t i = 0; i < 3; i++)
    {
        for (size_t j = 0; j<3; j++)
        {
            if(chboard_date[i][j] == '_')
               return false;
        }
    }

    return true;

}

//������������
void DrawBoard()
{
    line(0, 200, 600, 200);
    line(0, 400, 600, 400);
    line(200, 0, 200, 600);
    line(400, 0, 400, 600);
}
//��������
void DrawPiece()
{
    for (size_t i =0; i < 3; i++)
    {
        for (size_t j =0; j<3; j++)
        {
            switch (chboard_date[i][j])
            {
            case 'O':
                circle(200 *j+100 ,200 *i +100,100);
                break;
            case 'X':
                line(200 * j,200 * i, 200 *(j+1),200 *(i+1));
                line(200 * (j+1),200 * i,200 * j,200 * (i+1));
                break;
            case '_':
                break;
            default:
                break;
            }
        }
    }

}
//������ʾ��Ϣ
void DrawTipText()
{
    static TCHAR str[64];
    _stprintf_s(str, _T("��ǰ��������: %c"),current_piece);

    settextcolor(RGB(224,175,45));
    outtextxy(0,0,str);

}

int main()
{
    initgraph(600,600);

    bool running =true;

    ExMessage msg;

    BeginBatchDraw();
    DWORD start_time = GetTickCount();

    while (running)
    {
       while (peekmessage(&msg))
       {
            //����������������µ���Ϣ

            if (msg.message == WM_LBUTTONDOWN)
            {
                //������λ��

                int x = msg.x;
                int y = msg.y;
                
                int index_x = x / 200;
                int index_y = y / 200;

                //��������

                if (chboard_date[index_y][index_x] == '_')
                {
                    chboard_date[index_y][index_x] = current_piece;

                    //�л���������

                    if (current_piece == 'O')
                       current_piece = 'X';
                    else 
                        current_piece = 'O';
                      
                }
            }
       }
       cleardevice();

       DrawBoard();
       DrawPiece();
       DrawTipText();

       FlushBatchDraw();

       if (Checkwin('x'))
       {
            MessageBox(GetHWnd(),_T("X ��һ�ʤ "),_T(" ��Ϸ����"),MB_OK);
            running = false;
       }
      else if (Checkwin('O'))
       {
            MessageBox(GetHWnd(),_T("O ��һ�ʤ "),_T(" ��Ϸ����"),MB_OK);
            running = false;
       }
       else if (CheckDraw())
       {
            MessageBox(GetHWnd(),_T("û����һ�ʤ��ƽ�� "),_T(" ��Ϸ����"),MB_OK);
            running = false;
       }

       DWORD end_time = GetTickCount();
       DWORD delta_time = end_time -start_time;
       if (delta_time <1000 / 60)
       {
           Sleep(1000 / 60 - delta_time);
       }
    }

    return 0;
    
}