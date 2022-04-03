#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <iostream>
#include <cstdlib>
#include <stdio.h>
using namespace std;

const float FPS = 5;                                                    //Define a velocidade do jogo
const int SCREEN_W = 500;                                               //Define a largura do jogo
const int SCREEN_H = 550;                                               //Define altura do jogo
const int QUAD_SIZE = 20;                                               //Adptar o tamanho do quadrado para matriz
char MAPA[26][26] =                                                     //Matriz que define o mapa
    {
        "1111111111111111111111111",
        "1#######################1",
        "1#000000000000000000000#1",
        "1#000000000000000000000#1",
        "1#000000000000000000000#1",
        "1#000000000000000000000#1",
        "1#000000000000000000000#1",
        "1#000000000000000000000#1",
        "1#000000000000000000000#1",
        "1#000000000000000000000#1",
        "1#000000000000000000000#1",
        "1#000000000000000000000#1",
        "1#000000000000000000000#1",
        "1#000000000000000000000#1",
        "1#000000000000000000000#1",
        "1#000000000000000000000#1",
        "1#000000000000000000000#1",
        "1#000000000000000000000#1",
        "1#000000000000000000000#1",
        "1#000000000000000000000#1",
        "1#000000000000000000000#1",
        "1#000000000000000000000#1",
        "1#000000000000000000000#1",
        "1#######################1",
        "1111111111111111111111111",
};

ALLEGRO_DISPLAY *display = NULL;
ALLEGRO_EVENT_QUEUE *event_queue = NULL;
ALLEGRO_TIMER *timer = NULL;
ALLEGRO_BITMAP *mapa = NULL;
ALLEGRO_BITMAP *quad = NULL;                                           //Desenha corpo da minhoca
ALLEGRO_BITMAP *mapa_bordas = NULL;
ALLEGRO_FONT *fonte = NULL;
ALLEGRO_BITMAP *menu_imagem = NULL;                                    //Imagem da tela de inicio e morte
ALLEGRO_BITMAP *mapa_fundo = NULL;
ALLEGRO_BITMAP *coelho = NULL;
ALLEGRO_BITMAP *snake_cabeca_cima = NULL;
ALLEGRO_BITMAP *snake_cabeca_dir = NULL;
ALLEGRO_BITMAP *snake_cabeca_esq = NULL;
ALLEGRO_BITMAP *snake_cabeca_bai = NULL;
ALLEGRO_BITMAP *snake_corpo_cima = NULL;
ALLEGRO_BITMAP *corpolateral = NULL;
ALLEGRO_BITMAP *sapo = NULL;


int snake_rastro[26][26] = {0};                                         //Identifica onde a snake passou
int snake_passo = -1;                                                   //Quantos a snake ja andou
int cont_tam = 0;
int contador = 0;    
int cont_menu_morte = 0;                                                //Contador que do tempo da tela de morte                                                   //Variavel que impede da minhoca morrer antes de andar 3 casas 
int coelho_posicaox,coelho_posicaoy;
int sapo_posicaox,sapo_posicaoy;
int i = 15, j = 12;                                                     //Posicao inicial da Snake na matriz
int q = 20;                                                             //Tamanho de cada celula no mapa
int posy = i * q;                                                       //Posicao horizontal da Snake no display
int posx = j * q;                                                       //Posicao vertical da Snake no display
int snake_tamanho_ini = 4;                                              //Define o tamanho inical da cobra
bool redraw = true;                                                     //Booleano que permite fazer os desenhos do bitmap
bool sair = false;                                                      //Booleano que fecha o jogo quando aperta ESC
bool cima, baixo, esq, dir;                                             //Booleano que controlam as setas apertadas pelo jogador        
bool snake_encosta_dir = false;                                         //Booleano que controla o jogador se escontar pelo lado direito
bool snake_encosta_esq = false;                                         //Booleano que controla o jogador se escontar pelo lado esquerdo
bool snake_encosta_bax = false;                                         //Booleano que controla o jogador se escontar pelo lado baixo
bool snake_encosta_cim = false;                                         //Booleano que controla o jogador se escontar pelo lado cima
bool boo_menu = true;                                                   //Booleano que impede o menu inicial de aparacer mais de 1 vez
bool boo_menu_enter = false;     
bool coelhobool = true;                                       //Booleano que verifica se a pessoa aperteu enter para iniciar jogo

int inicializa()
{
    if (!al_init())                                                     //Inicializa allegro
    {
        cout << "Falha ao carregar Allegro" << endl;
        return 0;
    }

    if (!al_install_keyboard())                                          //Inicialisa funções do teclado do allegro
    {
        cout << "Falha ao inicializar o teclado" << endl;
        return 0;
    }

    timer = al_create_timer(1.0 / FPS);                                     //Cria um timer para velocidade do jogo
    if (!timer)
    {
        cout << "Falha ao inicializar o temporizador" << endl;
        return 0;
    }
  
    if (!al_init_image_addon())                                             //Inicialisa addon do allagro
    {
        cout << "Falha ao iniciar al_init_image_addon!" << endl;
        return 0;
    }

    display = al_create_display(SCREEN_W, SCREEN_H);                       //Inicialisa o tamanho da tela             
    if (!display)
    {
        cout << "Falha ao inicializar a tela" << endl;
        al_destroy_timer(timer);
        return 0;
    }

    mapa_fundo = al_load_bitmap("snakefundo.bmp");                          //Carrega a imagem de fundo do mapa
    if (!mapa_fundo)
    {
        cout << "Falha ao carregar o fundo!" << endl;
        al_destroy_bitmap(mapa_fundo);
        return 0;
    }

    mapa = al_load_bitmap("terreno.bmp");                                     //Carrega a segunda imagem de fundo do mapa      
    if (!mapa)
    {
        cout << "Falha ao carregar o mapa!" << endl;
        al_destroy_display(display);
        return 0;
    }

    menu_imagem = al_load_bitmap("capa.bmp");                               //Carrega a imagem do menu inicial e final
    if (!menu_imagem)
    {
        cout << "Falha ao carregar o menu!" << endl;
        al_destroy_bitmap(menu_imagem);
        return 0;
    }

    al_draw_bitmap(mapa, 0, 0, 0);
    quad = al_create_bitmap(QUAD_SIZE, QUAD_SIZE);                          //Cria um bitmap 20 x 20
    if (!quad)
    {
        al_destroy_display(display);
        al_destroy_timer(timer);
        return -1;
    }

    coelho = al_load_bitmap("coelho.bmp");                                 //Carrega a imagem do coelho    
    if(!coelho)
    {     
        cout << "Falha ao carregar o coelho!" << endl;
        al_destroy_bitmap(coelho);
        return -1;
    }

    mapa_bordas = al_load_bitmap("piso.bmp");                              //Carrega a imagem das bordas
    if (!mapa_bordas)
    {
        al_destroy_display(display);
        al_destroy_timer(timer);
        return -1;
    }

    snake_cabeca_cima = al_load_bitmap("cabecacimaaa.bmp");                //Carrega a imagem da cabeça da snake indo para cima 
    if (!snake_cabeca_cima)
    {
        cout << "Falha ao carregar a cabeça!" << endl;
        al_destroy_bitmap(snake_cabeca_cima);
        return -1;
    }

    snake_cabeca_dir = al_load_bitmap("cabecadir.bmp");                    //Carrega a imagem da cabeça da snake indo para direita 
    if (!snake_cabeca_dir)
    {
        cout << "Falha ao carregar a cabeça direita!" << endl;
        al_destroy_bitmap(snake_cabeca_dir);
        return -1;
    }

    snake_cabeca_bai = al_load_bitmap("cabecabaixo.bmp");                  //Carrega a imagem da cabeça da snake indo para baixo 
    if (!snake_cabeca_bai)
    {
        cout << "Falha ao carregar a cabeça baixos!" << endl;
        al_destroy_bitmap(snake_cabeca_bai);
        return -1;
    }

    snake_cabeca_esq = al_load_bitmap("cabecaesq.bmp");                     //Carrega a imagem da cabeça da snake indo para esquerda
    if (!snake_cabeca_esq)
    {
        cout << "Falha ao carregar a cabeça esquerda!" << endl;
        al_destroy_bitmap(snake_cabeca_esq);
        return -1;
    }

    snake_corpo_cima = al_load_bitmap("corpo.bmp");                          
    if (!snake_corpo_cima)
    {
        cout << "Falha ao carregar o corpo!" << endl;
        al_destroy_bitmap(snake_corpo_cima);
        return -1;
    }
    sapo = al_load_bitmap("sapo.bmp");
        if(!sapo)
        {
            cout << "Falha ao carregar o sapo" << endl;
            al_destroy_bitmap(sapo);
            return -1;
        }

    al_init_font_addon();                                           // Inicialização do add-on para uso de fontes
    if (!al_init_ttf_addon())                                       // Inicialização do add-on para uso de fontes True Type
    {
        fprintf(stderr, "Falha ao inicializar add-on allegro_ttf.\n");
        return -1;
    }

    fonte = al_load_font("ANDREDA10.TTF", 55, 0);                   // Carregando o arquivo de fonte
    if (!fonte)
    {
        al_destroy_display(display);
        fprintf(stderr, "Falha ao carregar fonte.\n");
        return -1;
    }

    al_set_target_bitmap(quad);                                     //Muda destino dos desenhos para o bitmap quad
    al_clear_to_color(al_map_rgb(rand() % 255, 0, rand() % 255));   //Limpa e colore de magenta
    al_set_target_bitmap(al_get_backbuffer(display));               //Muda de volta o destino dos desenhos para o display

    event_queue = al_create_event_queue();
    if (!event_queue)
    {
        cout << "Falha ao criar a fila de eventos" << endl;
        al_destroy_bitmap(quad);
        al_destroy_display(display);
        al_destroy_timer(timer);
        return 0;
    }

    al_register_event_source(event_queue, al_get_display_event_source(display));
    al_register_event_source(event_queue, al_get_timer_event_source(timer));
    al_register_event_source(event_queue, al_get_keyboard_event_source());

    al_clear_to_color(al_map_rgb(0, 0, 0));
    al_flip_display();
    al_start_timer(timer);

    return 1;
}

int main(int argc, char **argv)
{
    if (!inicializa()) {
        return -1;
    }

    int cont = 0;
    int time2 = 0;
    int cont1 = 0;
    int cont2 = 0;
    int cont3 = 0;
    int pontos = 0;
    cima = false;
    baixo = false;
    esq = false;
    dir = false;
    int c[26][26];
    srand(time(NULL));
    coelho_posicaox = rand() % 15 + 5;
    coelho_posicaoy = rand() % 15 + 5;                          //o coelho incia em uma posiçao aleatoria
    bool sapobool = false;
    

    while (!sair)
    {

        ALLEGRO_EVENT ev;
        al_wait_for_event(event_queue, &ev);

        if (ev.keyboard.keycode == ALLEGRO_KEY_ENTER)
        {
            boo_menu_enter = true;
        }

        if (ev.type == ALLEGRO_EVENT_TIMER)
        {

            snake_passo++;
            snake_rastro[i][j] = snake_passo;
            if (cima && MAPA[i - 1][j] != '1')
            {
                i--;
                posy = i * q;
               
            }
            if (cima && MAPA[i - 1][j] == '1')
            {
                snake_encosta_cim = true;
                     
            }
            if (baixo && MAPA[i + 1][j] != '1')
            {
                i++;
                posy = i * q;
            }
            if (baixo && MAPA[i + 1][j] == '1')
            {
                snake_encosta_bax = true;
            }
            if (esq && MAPA[i][j - 1] != '1')
            {
                j--;
                posx = j * q;
            }
            if (esq && MAPA[i][j - 1] == '1')
            {
                snake_encosta_esq = true;
            }

            if (dir && MAPA[i][j + 1] != '1')
            {
                j++;
                posx = j * q;
                
            }
            if (dir && MAPA[i][j + 1] == '1')
            {
                snake_encosta_dir = true;
            }

            if(posx == (sapo_posicaox * 20) && posy == (sapo_posicaoy * 20)){
                   snake_tamanho_ini +=2;
                   pontos += 3;
                   
                coelho_posicaox = rand() % 15 + 5;
                coelho_posicaoy = rand() % 15 + 5;
                coelhobool = true;
            }



            if (posx == (coelho_posicaox * 20) && posy == (coelho_posicaoy * 20))
            {
                snake_tamanho_ini++;
                pontos++;
                contador++;
                if(contador % 4 != 0){                          //sapo aparece de 4 em 4 coelhos.
                  coelho_posicaox = rand() % 15 + 5;                        //posiçao aleatoria do coelho 
                  coelho_posicaoy = rand() % 15 + 5;
                }
                else{
                    sapo_posicaox = rand() % 15 + 5;                  //posiçao aleatoria do sapo
                    sapo_posicaoy = rand() % 15 + 5;
                    sapobool = true;
                    coelhobool = false;
                }



            }

            redraw = true;
        }
        else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
        {
            break;
        }
        else if (ev.type == ALLEGRO_EVENT_KEY_DOWN)
        {
            switch (ev.keyboard.keycode)
            {
            case ALLEGRO_KEY_UP: //setinha pra cima

                if (baixo == true)
                    cima = false;
                else
                {
                    cima = true;
                    baixo = false;
                    esq = false;
                    dir = false;
                }
                break;

            case ALLEGRO_KEY_DOWN: //setinha pra baixo

                if (cima == true)
                    baixo = false;
                else
                {
                    cima = false;
                    baixo = true;
                    esq = false;
                    dir = false;
                }
                break;

            case ALLEGRO_KEY_LEFT: //setinha pra esquerda

                if (dir == true)
                    esq = false;
                else
                {
                    cima = false;
                    baixo = false;
                    esq = true;
                    dir = false;
                }
                break;

            case ALLEGRO_KEY_RIGHT: //setinha pra direita
                if (esq == true)
                    dir = false;
                else
                {
                    cima = false;
                    baixo = false;
                    esq = false;
                    dir = true;
                }
                break;
            }
        }
        else if (ev.type == ALLEGRO_EVENT_KEY_UP)

        {
            switch (ev.keyboard.keycode)
            {
            case ALLEGRO_KEY_ESCAPE: //tecla ESC
                sair = true;
                break;
            }
        }
        if (boo_menu == true)
        {
            if (time2 > 6)
                time2 = 0;
            al_clear_to_color(al_map_rgb(0, 0, 0));
            al_draw_bitmap(menu_imagem, 0, 0, 0);                                 //desenha o menu do jogo,com a pixel art da cobrinha
            if (time2 < 5)                                   //Aqui fica piscando o PRESS ENTER
                al_draw_text(fonte, al_map_rgb(0, 0, 0), 250, 400, ALLEGRO_ALIGN_CENTER, "Press Enter");
            al_flip_display();
            if (boo_menu_enter == true)    //JOGO COMEÇA QUANDO É PRESSIONADO ENTER.
                boo_menu = false;
            time2++;
        }

        if (boo_menu_enter == true)
        {

            if (redraw && al_is_event_queue_empty(event_queue))

            {
                redraw = false;

                al_clear_to_color(al_map_rgb(0, 0, 0));
                al_draw_bitmap(mapa, 0, 0, 0);
                al_draw_bitmap(mapa_fundo, 0, 0, 0);          
                
                for (int i = 0; i < 26; i++)
                    for (int j = 0; j < 26; j++)
                    {
                        // if (snake_rastro[i][j] > 0 && snake_rastro[i][j] >= snake_passo - snake_tamanho_ini) //se passou aqui nos ultimos 4 passos
                        //     al_draw_bitmap(quad, j * q, i * q, 0);             //desenha quadrado
                        if (MAPA[i][j] == '#' || MAPA[i][j] == '1')             
                        {
                            al_draw_bitmap(mapa_bordas, j * q, i * q, 0); //desenho das bordas do jogo
                        }
                        if (MAPA[i][j] == '0'){
                            al_draw_bitmap(mapa,j*q,i*q,0);           //desenho do mapa de fundo,terreno.
                        }
                         if(cima && MAPA[i - 1][j] != '1')
                                   al_draw_bitmap(snake_cabeca_cima,posx ,posy,0);
                         if (dir && MAPA[i][j + 1] != '1')
                                  { al_draw_bitmap(snake_cabeca_dir,posx ,posy,0);
               
                                   }                                                     //desenho da cabeça da snake para diferentes posiçoes que ela vira
                         if (baixo && MAPA[i + 1][j] != '1')
                                         al_draw_bitmap(snake_cabeca_bai,posx,posy,0);
                         if (esq && MAPA[i][j - 1] != '1')
                                        al_draw_bitmap(snake_cabeca_esq,posx,posy,0);
    

                         if (snake_rastro[i][j] > 0 && snake_rastro[i][j] >= snake_passo - snake_tamanho_ini){ //se passou aqui nos ultimos 4 passos                
                            if (dir && MAPA[i][j + 1] != '1' || esq && MAPA[i][j - 1] != '1' )
                                        al_draw_bitmap(snake_corpo_cima, j * q, i * q, 0);
                            if(cima && MAPA[i - 1][j] != '1' || baixo && MAPA[i + 1][j] != '1')          //mudança no corpo quando ela muda de posiçao     
                                         al_draw_bitmap(snake_corpo_cima, j * q, i * q, 0);
                         }
                             
                         }
                         
            
                
                al_draw_text(fonte, al_map_rgb(rand() % 255, rand() % 255, rand() % 255), 10, 500, ALLEGRO_ALIGN_LEFT, "SNAKEE"); //Nome do jogo
                al_draw_textf(fonte, al_map_rgb_f(rand()%255, 0, rand()%255), 250,500, 500, "Score  %d", pontos); //pontuaçao do jogo
                 if(coelhobool == true){ 
                al_draw_bitmap(coelho, coelho_posicaox * q, coelho_posicaoy * q, 0);    //desenho do coelho
                al_set_target_bitmap(coelho);
                 }
                if(sapobool == true){
                    al_draw_bitmap(sapo,sapo_posicaox * q,sapo_posicaoy * q,0);   //desenho do sapo
                    al_set_target_bitmap(sapo);
                }
                al_set_target_bitmap(al_get_backbuffer(display));  
                al_flip_display();
                if (cont_tam > snake_tamanho_ini)
                {
                    if (snake_rastro[i][j] < snake_passo && snake_rastro[i][j] > (snake_passo - snake_tamanho_ini))
                    {
                        al_draw_bitmap(quad, j * q, i * q, 0);
                    

                        while (cont_menu_morte < 2000)
                        {
                            al_clear_to_color(al_map_rgb(0, 0, 0));
                            al_draw_bitmap(menu_imagem, 0, 0, 0);

                            al_draw_text(fonte, al_map_rgb(0, 0, 0), 250, 400, ALLEGRO_ALIGN_CENTER, "VOCE MORREU"); 
                            al_flip_display();
                            cont_menu_morte++;                      //contador,para o "VOCE MORREU" ficar aparecendo na tela
                        }
                        al_destroy_bitmap(quad);
                        al_destroy_bitmap(mapa);
                        al_destroy_timer(timer);
                        al_destroy_display(display);
                        al_destroy_event_queue(event_queue);
                        al_destroy_font(fonte);
                        al_destroy_bitmap(menu_imagem);
                        al_destroy_bitmap(mapa_fundo);
                        al_destroy_bitmap(snake_cabeca_cima);            //destroi o que foi usado
                        al_destroy_bitmap(snake_cabeca_dir);
                        al_destroy_bitmap(snake_cabeca_esq);
                        al_destroy_bitmap(snake_cabeca_bai);
                        al_destroy_bitmap(corpolateral);
                        al_destroy_bitmap(snake_corpo_cima);
                        al_destroy_bitmap(coelho);
                        al_destroy_bitmap(sapo);
                        return 0;
                    }
                }
                cont_tam++;
                if (snake_encosta_esq == true)
                {
                    redraw = false;

                    while (cont_menu_morte < 2000)
                    {
                        al_clear_to_color(al_map_rgb(0, 0, 0));
                        al_draw_bitmap(menu_imagem, 0, 0, 0);

                        al_draw_text(fonte, al_map_rgb(0, 0, 0), 250, 400, ALLEGRO_ALIGN_CENTER, "VOCE MORREU");
                        al_flip_display();
                        cont_menu_morte++;
                    }

                    al_destroy_bitmap(quad);
                    al_destroy_bitmap(mapa);
                    al_destroy_timer(timer);
                    al_destroy_display(display);
                    al_destroy_event_queue(event_queue);
                    al_destroy_font(fonte);
                    al_destroy_bitmap(menu_imagem);
                    al_destroy_bitmap(mapa_fundo);
                    al_destroy_bitmap(snake_cabeca_cima);
                    al_destroy_bitmap(snake_cabeca_dir);
                    al_destroy_bitmap(snake_cabeca_esq);
                    al_destroy_bitmap(snake_cabeca_bai);
                    al_destroy_bitmap(corpolateral);
                    al_destroy_bitmap(snake_corpo_cima);
                    al_destroy_bitmap(coelho);
                    al_destroy_bitmap(sapo);
                    return 0;
                }
                if (snake_encosta_dir == true)
                {
                    redraw = false;

                    while (cont_menu_morte < 2000)
                    {
                        al_clear_to_color(al_map_rgb(0, 0, 0));
                        al_draw_bitmap(menu_imagem, 0, 0, 0);

                        al_draw_text(fonte, al_map_rgb(0, 0, 0), 250, 400, ALLEGRO_ALIGN_CENTER, "VOCE MORREU");
                        al_flip_display();
                        cont_menu_morte++;
                    }
                    al_destroy_bitmap(quad);
                    al_destroy_bitmap(mapa);
                    al_destroy_timer(timer);
                    al_destroy_display(display);
                    al_destroy_event_queue(event_queue);
                    al_destroy_font(fonte);
                    al_destroy_bitmap(menu_imagem);
                    al_destroy_bitmap(mapa_fundo);
                    al_destroy_bitmap(snake_cabeca_cima);
                    al_destroy_bitmap(snake_cabeca_dir);
                    al_destroy_bitmap(snake_cabeca_esq);
                    al_destroy_bitmap(snake_cabeca_bai);
                    al_destroy_bitmap(corpolateral);
                    al_destroy_bitmap(snake_corpo_cima);
                    al_destroy_bitmap(coelho);
                    al_destroy_bitmap(sapo);
                    return 0;
                }
                if (snake_encosta_cim == true)
                {
                    redraw = false;

                    while (cont_menu_morte < 2000)
                    {
                        al_clear_to_color(al_map_rgb(0, 0, 0));
                        al_draw_bitmap(menu_imagem, 0, 0, 0);

                        al_draw_text(fonte, al_map_rgb(0, 0, 0), 250, 400, ALLEGRO_ALIGN_CENTER, "VOCE MORREU");
                        al_flip_display();
                        cont_menu_morte++;
                    }

                    al_flip_display();
                    al_destroy_bitmap(quad);
                    al_destroy_bitmap(mapa);
                    al_destroy_timer(timer);
                    al_destroy_display(display);
                    al_destroy_event_queue(event_queue);
                    al_destroy_font(fonte);
                    al_destroy_bitmap(menu_imagem);
                    al_destroy_bitmap(mapa_fundo);
                    al_destroy_bitmap(snake_cabeca_cima);
                    al_destroy_bitmap(snake_cabeca_dir);
                    al_destroy_bitmap(snake_cabeca_esq);
                    al_destroy_bitmap(snake_cabeca_bai);
                    al_destroy_bitmap(corpolateral);
                    al_destroy_bitmap(snake_corpo_cima);
                    al_destroy_bitmap(coelho);
                    al_destroy_bitmap(sapo);
                    return 0;
                }
                if (snake_encosta_bax == true)
                {
                    redraw = false;

                    while (cont_menu_morte < 2000)
                    {
                        al_clear_to_color(al_map_rgb(0, 0, 0));
                        al_draw_bitmap(menu_imagem, 0, 0, 0);

                        al_draw_text(fonte, al_map_rgb(0, 0, 0), 250, 400, ALLEGRO_ALIGN_CENTER, "VOCE MORREU");
                        al_flip_display();
                        cont_menu_morte++;
                    }
                    al_destroy_bitmap(quad);
                    al_destroy_bitmap(mapa);
                    al_destroy_timer(timer);
                    al_destroy_display(display);
                    al_destroy_event_queue(event_queue);
                    al_destroy_font(fonte);
                    al_destroy_bitmap(menu_imagem);
                    al_destroy_bitmap(mapa_fundo);
                    al_destroy_bitmap(snake_cabeca_cima);
                    al_destroy_bitmap(snake_cabeca_dir);
                    al_destroy_bitmap(snake_cabeca_bai);
                    al_destroy_bitmap(snake_cabeca_esq);
                    al_destroy_bitmap(corpolateral);
                    al_destroy_bitmap(snake_corpo_cima);
                    al_destroy_bitmap(coelho);
                    al_destroy_bitmap(sapo);
                    return 0;
                }
            }
        }
    }

    al_destroy_bitmap(quad);
    al_destroy_bitmap(mapa);
    al_destroy_timer(timer);
    al_destroy_display(display);
    al_destroy_event_queue(event_queue);
    al_destroy_font(fonte);
    al_destroy_bitmap(menu_imagem);
    al_destroy_bitmap(mapa_fundo);
    al_destroy_bitmap(snake_cabeca_cima);
    al_destroy_bitmap(snake_cabeca_dir);
    al_destroy_bitmap(snake_cabeca_bai);
    al_destroy_bitmap(snake_cabeca_esq);
    al_destroy_bitmap(corpolateral);
    al_destroy_bitmap(snake_corpo_cima);
    al_destroy_bitmap(coelho);
    al_destroy_bitmap(sapo);
    return 0;
}