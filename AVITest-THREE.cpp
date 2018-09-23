// **********************************************************************
// PUCRS/FACIN
// COMPUTA��O GR�FICA
//
// Arquivo: AVITest.cpp
//
// Programa de testes para carga de Imagens e v�deos AVI
//
//  Este programa deve ser compilador junto com a classe "ImageClass",
//  que est� implementada no arquivo "ImageClass.cpp"
//
//  Para a carga das imagens este programa utiliza a biblioteca
//  IM http://www.tecgraf.puc-rio.br/im de autoria de Antonio Scuri
//
// Marcio Serolli Pinho
// 12/08/2003
//  pinho@inf.pucrs.br
// **********************************************************************

#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;

#include "AVIClass.h"
#include "Ponto.h"

#define MED_SIZE 9

double colors[256][3] = {
    {0, 0, 0},
    {128, 0, 0},
    {0, 128, 0},
    {128, 128, 0},
    {0, 0, 128},
    {128, 0, 128},
    {0, 128, 128},
    {192, 192, 192},
    {128, 128, 128},
    {255, 0, 0},
    {0, 255, 0},
    {255, 255, 0},
    {0, 0, 255},
    {255, 0, 255},
    {0, 255, 255},
    {255, 255, 255},
    {0, 0, 0},
    {0, 0, 95},
    {0, 0, 135},
    {0, 0, 175},
    {0, 0, 215},
    {0, 0, 255},
    {0, 95, 0},
    {0, 95, 95},
    {0, 95, 135},
    {0, 95, 175},
    {0, 95, 215},
    {0, 95, 255},
    {0, 135, 0},
    {0, 135, 95},
    {0, 135, 135},
    {0, 135, 175},
    {0, 135, 215},
    {0, 135, 255},
    {0, 175, 0},
    {0, 175, 95},
    {0, 175, 135},
    {0, 175, 175},
    {0, 175, 215},
    {0, 175, 255},
    {0, 215, 0},
    {0, 215, 95},
    {0, 215, 135},
    {0, 215, 175},
    {0, 215, 215},
    {0, 215, 255},
    {0, 255, 0},
    {0, 255, 95},
    {0, 255, 135},
    {0, 255, 175},
    {0, 255, 215},
    {0, 255, 255},
    {95, 0, 0},
    {95, 0, 95},
    {95, 0, 135},
    {95, 0, 175},
    {95, 0, 215},
    {95, 0, 255},
    {95, 95, 0},
    {95, 95, 95},
    {95, 95, 135},
    {95, 95, 175},
    {95, 95, 215},
    {95, 95, 255},
    {95, 135, 0},
    {95, 135, 95},
    {95, 135, 135},
    {95, 135, 175},
    {95, 135, 215},
    {95, 135, 255},
    {95, 175, 0},
    {95, 175, 95},
    {95, 175, 135},
    {95, 175, 175},
    {95, 175, 215},
    {95, 175, 255},
    {95, 215, 0},
    {95, 215, 95},
    {95, 215, 135},
    {95, 215, 175},
    {95, 215, 215},
    {95, 215, 255},
    {95, 255, 0},
    {95, 255, 95},
    {95, 255, 135},
    {95, 255, 175},
    {95, 255, 215},
    {95, 255, 255},
    {135, 0, 0},
    {135, 0, 95},
    {135, 0, 135},
    {135, 0, 175},
    {135, 0, 215},
    {135, 0, 255},
    {135, 95, 0},
    {135, 95, 95},
    {135, 95, 135},
    {135, 95, 175},
    {135, 95, 215},
    {135, 95, 255},
    {135, 135, 0},
    {135, 135, 95},
    {135, 135, 135},
    {135, 135, 175},
    {135, 135, 215},
    {135, 135, 255},
    {135, 175, 0},
    {135, 175, 95},
    {135, 175, 135},
    {135, 175, 175},
    {135, 175, 215},
    {135, 175, 255},
    {135, 215, 0},
    {135, 215, 95},
    {135, 215, 135},
    {135, 215, 175},
    {135, 215, 215},
    {135, 215, 255},
    {135, 255, 0},
    {135, 255, 95},
    {135, 255, 135},
    {135, 255, 175},
    {135, 255, 215},
    {135, 255, 255},
    {175, 0, 0},
    {175, 0, 95},
    {175, 0, 135},
    {175, 0, 175},
    {175, 0, 215},
    {175, 0, 255},
    {175, 95, 0},
    {175, 95, 95},
    {175, 95, 135},
    {175, 95, 175},
    {175, 95, 215},
    {175, 95, 255},
    {175, 135, 0},
    {175, 135, 95},
    {175, 135, 135},
    {175, 135, 175},
    {175, 135, 215},
    {175, 135, 255},
    {175, 175, 0},
    {175, 175, 95},
    {175, 175, 135},
    {175, 175, 175},
    {175, 175, 215},
    {175, 175, 255},
    {175, 215, 0},
    {175, 215, 95},
    {175, 215, 135},
    {175, 215, 175},
    {175, 215, 215},
    {175, 215, 255},
    {175, 255, 0},
    {175, 255, 95},
    {175, 255, 135},
    {175, 255, 175},
    {175, 255, 215},
    {175, 255, 255},
    {215, 0, 0},
    {215, 0, 95},
    {215, 0, 135},
    {215, 0, 175},
    {215, 0, 215},
    {215, 0, 255},
    {215, 95, 0},
    {215, 95, 95},
    {215, 95, 135},
    {215, 95, 175},
    {215, 95, 215},
    {215, 95, 255},
    {215, 135, 0},
    {215, 135, 95},
    {215, 135, 135},
    {215, 135, 175},
    {215, 135, 215},
    {215, 135, 255},
    {215, 175, 0},
    {215, 175, 95},
    {215, 175, 135},
    {215, 175, 175},
    {215, 175, 215},
    {215, 175, 255},
    {215, 215, 0},
    {215, 215, 95},
    {215, 215, 135},
    {215, 215, 175},
    {215, 215, 215},
    {215, 215, 255},
    {215, 255, 0},
    {215, 255, 95},
    {215, 255, 135},
    {215, 255, 175},
    {215, 255, 215},
    {215, 255, 255},
    {255, 0, 0},
    {255, 0, 95},
    {255, 0, 135},
    {255, 0, 175},
    {255, 0, 215},
    {255, 0, 255},
    {255, 95, 0},
    {255, 95, 95},
    {255, 95, 135},
    {255, 95, 175},
    {255, 95, 215},
    {255, 95, 255},
    {255, 135, 0},
    {255, 135, 95},
    {255, 135, 135},
    {255, 135, 175},
    {255, 135, 215},
    {255, 135, 255},
    {255, 175, 0},
    {255, 175, 95},
    {255, 175, 135},
    {255, 175, 175},
    {255, 175, 215},
    {255, 175, 255},
    {255, 215, 0},
    {255, 215, 95},
    {255, 215, 135},
    {255, 215, 175},
    {255, 215, 215},
    {255, 215, 255},
    {255, 255, 0},
    {255, 255, 95},
    {255, 255, 135},
    {255, 255, 175},
    {255, 255, 215},
    {255, 255, 255},
    {8, 8, 8},
    {18, 18, 18},
    {28, 28, 28},
    {38, 38, 38},
    {48, 48, 48},
    {58, 58, 58},
    {68, 68, 68},
    {78, 78, 78},
    {88, 88, 88},
    {98, 98, 98},
    {108, 108, 108},
    {118, 118, 118},
    {128, 128, 128},
    {138, 138, 138},
    {148, 148, 148},
    {158, 158, 158},
    {168, 168, 168},
    {178, 178, 178},
    {188, 188, 188},
    {198, 198, 198},
    {208, 208, 208},
    {218, 218, 218},
    {228, 228, 228},
    {238, 238, 238}
};

int cinza = true;
bool primeiraVez = true;

vector <Ponto*> listaPontos;

AVIClass Video;
ImageClass NewImage;
ImageClass NewImage2;

int offsets[MED_SIZE][2] = {{-1, -1}, {0, -1}, {1, -1}
                           ,{-1,  0}, {0,  0}, {1,  0}
                           ,{-1,  1}, {0,  1}, {1,  1}
                           };

double mediana_array[MED_SIZE];

void init(void)
{
cout << "Init..." ;
    glClearColor(0.0f, 0.0f, 1.0f, 1.0f); // Fundo de tela preto

    imFormatRegisterAVI();
    //imFormatRegisterWMV();
    if(Video.openVideoFile("videos\\VideoBike.avi") == 0)
    //if(Video.openVideoFile("Videos\\video_original.avi") == 0)
    {
       cout << "Problemas na abertura do video" << endl;
    }
    else cout << "Abertura OK ! - Nro de Frames:" << Video.getTotalFrames() << endl;
    cout << "Dimensoes do Video:" << Video.SizeX() << " x " << Video.SizeY() <<endl;

    NewImage.SetSize(Video.SizeX(), Video.SizeY(), Video.Channels());
    NewImage2.SetSize(Video.SizeX(), Video.SizeY(), Video.Channels());

    cout << "Fim." << endl;

}

void reshape( int w, int h )
{
    // Reset the coordinate system before modifying
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    // Set the viewport to be the entire window
    glViewport(0, 0, w, h);
    gluOrtho2D(0,w,0,h);

    // Set the clipping volume
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

}

void ConverteCinza(AVIClass V, ImageClass image)
{
    int x,y;
    int i;
    //cout << "Iniciou Black & White....";
    //NovaImagem->DrawPixel(20, 1,100,255,0,0 );

    for(x=0;x<V.SizeX();x++)
    {
        for(y=0;y<V.SizeY();y++)
        {
            i = V.GetPointIntensity(x,y);
            //Img->ReadPixel(x,y, r,g,b);
            if (i> 233)
              image.DrawPixel(x, y,255,255,255);
            else image.DrawPixel(x, y,0,0,0);
        }
    }
}

void swap(double* x, double* b)
{
	double aux;

	aux = *x;
	*x = *b;
	*b = aux;
}

int separate(double* vet, int value, int end)
{
	int pivot = vet[value];
	int i = value;
	int j = value + 1;

	while(j < end)
	{
		if(vet[j] < pivot)
		{
			i++;
			swap(&vet[i], &vet[j]);
		}
		j++;
	}
	swap(&vet[value], &vet[i]);

	return i;
}

void quicksort(double* vet, int i, int j)
{
	int separation;

	if(i < j)
	{
		separation = separate(vet, i, j);
		quicksort(vet, i, separation);
		quicksort(vet, separation + 1, j);
	}
}

void Mediana(AVIClass V, ImageClass in, ImageClass out)
{
    int x, y;
    for(x = 2; x < in.SizeX() - 2; x++)
    {
        for(y = 2; y < in.SizeY() - 2; y++)
        {
            for (int i = 0; i < MED_SIZE ; i++)
            {
                int xi = x + offsets[i][0];
                int yi = y + offsets[i][1];
                mediana_array[i] = in.GetPointIntensity(xi, yi);
            }
            quicksort(mediana_array, 0, MED_SIZE);
            int new_pixel = mediana_array[MED_SIZE / 2 + 1];
            out.DrawPixel(x, y, new_pixel, new_pixel, new_pixel);
        }
    }
}

void preencheArea(AVIClass V, ImageClass image, int x, int y, double r, double g, double b)
{
    V.DrawPixel(x, y, r, g, b);
    image.DrawPixel(x, y, 0, 0, 0);
    for(int i = 0; i < MED_SIZE; i++)
    {
        int xi = x + offsets[i][0];
        int yi = y + offsets[i][1];
        if (image.GetPointIntensity(xi, yi) == 255)
        {
            preencheArea(V, image, xi, yi, r, g, b);
        }
    }
}

void encontraAreas(AVIClass V, ImageClass in, ImageClass out)
{
    int x, y;
    for(x = 0; x < in.SizeX(); x++)
    {
        for(y = 0; y < in.SizeY(); y++)
        {
            double ponto = in.GetPointIntensity(x, y);
            out.DrawPixel(x, y, ponto, ponto, ponto);
        }
    }

    for(x = 2; x < out.SizeX() - 2; x++)
    {
        for(y = 2; y < out.SizeY() - 2; y++)
        {
            if (out.GetPointIntensity(x, y) == 255)
            {
                Ponto* p;
                if (primeiraVez)
                {
                    int rgb = x * y % 256;
                    p = new Ponto(x, y, colors[rgb][0], colors[rgb][1], colors[rgb][2]);
                    listaPontos.push_back(p);
                }
                else
                {
                    Ponto corrente;
                    corrente.setX(x);
                    corrente.setY(y);
                    Ponto* menor = listaPontos[0];
                    for(int i = 0; i < listaPontos.size(); i++)
                    {
                        Ponto* bepis = listaPontos[i];
                        if (menor->distancia(corrente) > bepis->distancia(corrente))
                        {
                            menor = bepis;
                        }
                    }
                    p = menor;
                    p->setX(x);
                    p->setY(y);
                }
                preencheArea(V, out, x, y, p->getR(), p->getG(), p->getB());
            }
        }
    }
    primeiraVez = false;
}

void CalculaNivelDeZoom(float &ZoomH, float &ZoomV)
{
     ZoomH = (float)glutGet(GLUT_WINDOW_WIDTH)/Video.SizeX();
     ZoomV = (float)glutGet(GLUT_WINDOW_HEIGHT)/Video.SizeY();
}
int frame = 1;

void display( void )
{

    int loadFrameOK;
    float ZoomH, ZoomV;

    glClear(GL_COLOR_BUFFER_BIT);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-10,10,-10,10,-1,1);

	glMatrixMode (GL_MODELVIEW);
	glLoadIdentity();

    loadFrameOK = Video.loadImageFrame(frame);
    // avan�a o nro do frame
    frame ++;
    cout << "Frame: " << frame << endl;
    // se atingiu o final do v�deo, ent�o recome�a
    if (frame == Video.getTotalFrames())
    {
         frame = 0;
        // getchar();
         return;
    }
    if (loadFrameOK)
    {

      // cout << "Imagem Exibida !!" << endl;
       Video.SetPos(-10,-10);
       // acerta o zoom da imagem para que ocupe toda a janela
       CalculaNivelDeZoom(ZoomH, ZoomV);
       Video.SetZoomH(ZoomH/2);
       Video.SetZoomV(ZoomV);
       NewImage.SetPos(0,-10);
       NewImage.SetZoomH(ZoomH/2);
       NewImage.SetZoomV(ZoomV);
       NewImage2.SetPos(0,-10);
       NewImage2.SetZoomH(ZoomH/2);
       NewImage2.SetZoomV(ZoomV);
       if (cinza)
       {
          ConverteCinza(Video, NewImage);
          Mediana(Video, NewImage, NewImage2);
          encontraAreas(Video, NewImage2, NewImage);
       }
       Video.Display();
       NewImage.Display();
       //NewImage2.Display();
    }
    else cout << "Erro..." << endl;

    glutSwapBuffers();
}


// **********************************************************************
//  void keyboard ( unsigned char key, int x, int y )
//
//
// **********************************************************************
void keyboard ( unsigned char key, int x, int y )
{

    switch ( key )
    {
        case 'c': cinza = !cinza;
                  glutPostRedisplay();
                  break;

        case ' ':
                   glutPostRedisplay();
                   break;
        case 27: // Termina o programa qdo
             Video.closeVideoFile();
        exit ( 0 );   // a tecla ESC for pressionada
        break;
        default:
        break;
    }
}

void arrow_keys ( int a_keys, int x, int y )
{
    switch ( a_keys )
    {
        case GLUT_KEY_UP:       // When Up Arrow Is Pressed...
        break;
        case GLUT_KEY_DOWN:     // When Down Arrow Is Pressed...

        break;
        default:
        break;
    }
}
int main ( int argc, char** argv )
{
    init ();

    glutInit            ( &argc, argv );
    glutInitDisplayMode (GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGB );
    glutInitWindowPosition (300,10);

    // Define o tamanho da janela gr�fica do programa
    glutInitWindowSize  ( 640, 480);
    glutCreateWindow    ( "AVI Loader - v2.0" );

    glutDisplayFunc ( display );
    glutReshapeFunc ( reshape );
    glutKeyboardFunc ( keyboard );
    glutSpecialFunc ( arrow_keys );
    //glutIdleFunc ( display );


   // MessageBox(NULL, "Pressione a barra de espa�o para avancar o v�deo.", "Mensagem", MB_OK);
    cout << "Pressione a barra de espa�o para avancar o v�deo." << endl;

    glutMainLoop ();
    cout <<"FIM\n";

    return 0;
}
