#include <iomanip>
#include <iostream>

struct Imagem {
    int **pixels; //matriz com os pixels da imagem
    int nrows; //numero de linhas na imagem (altura)
    int ncolumns; //numero de colunas na imagem (largura)
    char cTipImg[2]; //Tipo da imagem (P1,P2,P3)
};

void leImagem(Imagem &im) {
    
    int nCont,nCont2;

    std::cin >> im.cTipImg[0] >> im.cTipImg[1] >> im.ncolumns >> im.nrows;

    im.pixels = new int* [im.nrows];
    for (nCont = 0; nCont < im.nrows;nCont++) {
        im.pixels[nCont] = new int [im.ncolumns];
    }

    for (nCont = 0; nCont < im.nrows; nCont++) {
        for (nCont2 = 0; nCont2 < im.ncolumns; nCont2++) {
            std::cin >> im.pixels[nCont][nCont2];
        }
    }

}

void deletaImagem(Imagem im) {

    int nCont;

    for (nCont = 0; nCont < im.nrows; nCont++) {
        delete [] im.pixels[nCont];
    }
    delete [] im.pixels;
}

void imprimeImagem(Imagem im) {
    
    int nCont,nCont2;

    std::cout << im.cTipImg[0] << im.cTipImg[1] << std::endl;
    std::cout << im.ncolumns  << " " << im.nrows << std::endl;

    for (nCont = 0; nCont < im.nrows; nCont++) {
        for (nCont2 = 0; nCont2 < im.ncolumns; nCont2++) {
            std::cout << im.pixels[nCont][nCont2];
            if (nCont2 == im.ncolumns - 1) {
                std::cout << std::endl;
            }    
            else {
                std::cout << " ";
            }            
        }
    }    
}

void inverteCorImagem(Imagem im) {

    int nCont,nCont2;

    for (nCont = 0; nCont < im.nrows; nCont++) {
        for (nCont2 = 0; nCont2 < im.ncolumns; nCont2++) {
            if (im.pixels[nCont][nCont2] == 1) {
                im.pixels[nCont][nCont2] = 0;
            }
            else {
                im.pixels[nCont][nCont2] = 1;
            }
        }
    }
}

int main() { 
    
    Imagem im;

    leImagem(im); 
    inverteCorImagem(im); 
    imprimeImagem(im); 
    deletaImagem(im); 

    return 0;
}