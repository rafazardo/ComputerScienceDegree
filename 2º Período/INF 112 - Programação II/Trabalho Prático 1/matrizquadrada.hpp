struct MatrizQuadrada {

    int **_elementos; 
    int _ordem;  //Ordem da matriz nxn

    MatrizQuadrada(int ordemMatriz); //Construtor
    
    ~MatrizQuadrada(); //Destrutor

    void leMatriz(MatrizQuadrada &Matriz);

    void imprimeMatriz(MatrizQuadrada &Matriz);

    void criaMatrizIdentidade(MatrizQuadrada &Matriz);

    void produto(MatrizQuadrada &Matriz, MatrizQuadrada &matrizIdentidade, MatrizQuadrada &matrizResultante); 

    void criaTransposta(MatrizQuadrada &matrizResultante, MatrizQuadrada &matrizTransposta);

    void soma(MatrizQuadrada &matrizResultante, MatrizQuadrada &matrizA, MatrizQuadrada &matrizB);

    bool compara(MatrizQuadrada &Matriz, MatrizQuadrada &matrizResultante);
    
};