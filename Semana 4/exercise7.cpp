/**
 * Primeramente, creo cinco funciones:
 * 
 * 1. Funcion pow_two: nos calcula el numero que es potencia de dos que esta despues del numero
 * que le pasemos como argumento. Pero, en caso de que el numero que le pasemos es potencia de dos
 * entonces nos retorna el mismo numero.
 * 
 * 2. Funcion matrix_addition: Realiza la suma de matrices.
 * 
 * 3. Funcion matrix_subtraction: Realiza la resta de matrices.
 * 
 * 4. Funcion matrix_multiplication: Realiza la multiplicacion de matrices.
 * 
 * 5. Funcion strassen: Realiza el algoritmo de strassen.
 * 
 * Dentro de la funcion main primero creo unas variables que, seguidamente, tomaran valores segun los datos
 * del input.
 * 
 * Luego, creo las matrices A, B y C de tamaño n x n, donde el valor de n fue recibido como primer valor del 
 * input. Ademas, las matrices A y B tienen elementos de tipo unsigned int; mientras que, los elementos de la
 * matriz C son del tipo unsigned long long.
 * 
 * Luego, creo un vector llamado "V" y lo inicializo con tamaño n y todos sus elementos con cero.
 * 
 * Posteriormente, por medio de un bucle y utilizando los valores que fueron que fueron recibidos del input
 * (despues del valor de n), relleno las matrices A y B.
 * 
 * Luego, como sabemos que el algoritmo de Strassen funciona para matrices cuadradas cuyas cantidad de filas y
 * y columnas son potencias de dos, entonces aplico la funcion pow_two para obtener un numero que sea potencia
 * de dos y utilizarlo como tamaño de filas y columnas de las matrices que seran utilizadas en el algoritmo 
 * de Strassen. Dicho numero que retorne la funcion pow_two sera almacenado en una variable llamada "nnew".
 * 
 * Ahora, creo tres matrices llamadas Al, Bl y Cl, cada una de tamaño nnew x nnew y sus elementos son de tipo
 * unsigned long long. Posteriormente, por medio de un bucle, copiamos los elementos de la matriz A a la matriz
 * Al y tambien copiamos los elementos de la matriz B a la matriz Bl. Cabe destacar que para realizar dicha copia
 * convertimos el tipo de los elementos de las matrices A y B a un tipo unsigned long long a medida que vamos asignando
 * el valor a cada elemento de las matrices Al y Bl.
 * 
 * Luego, llamo la funcion strassen cuyos argumentos seran: Al, Bl, Cl, nnew y el numero 50. El numero 50 sera el que
 * utilizare para que cuando nnew sea menor o igual a dicho numero entonces se procede a realizar la multiplicacion de matrices
 * de la funcion matrix_multiplication (este proceso de comparacion se realiza dentro de la funcion strassen).
 * 
 * Posteriormente, copiamos los elementos de la matriz Cl (matriz que resulta de la multiplicacion de las matrices Al y Bl por
 * medio de la funcion strassen) a la matriz C. 
 * 
 * Luego, tenemos un bucle for que es extraido del codigo que esta en las instrucciones del ejercicio, y nos sirve para ir 
 * rellenando el vector V.
 * 
 * Finalmente, creo un bucle for para imprimir los valores del vector V por consola, el cual sera la respuesta final del ejercicio. 
*/

#include <iostream>
#include <vector>
#include <cmath>
#include <utility>
using namespace std;

/**
 * Funcion que segun el numero que le pasemos como argumento, nos retornara el siguiente
 * numero que es potencia de dos (en caso de que dicho argumento no sea un numero potencia
 * de dos) pero en caso de que ese argumento sea una potencia de dos entonces nos retornara
 * el mismo numero.
*/ 
int pow_two( int n )
{
    // Calcular el logaritmo base 2 del número.
    double logarithm = log2( n );

    // Redondear el logaritmo hacia arriba al entero más cercano.
    int exp = ceil( logarithm );

    // Calcular la siguiente potencia de 2.
    int next_pow = pow( 2, exp );

    return next_pow;
}

/**
 * Funcion que realiza la suma de matrices.
 * 
 * La Funcion recibe tres matrices cuadradas y un entero que indicara el tamaño de la matriz 
 * (si el entero es 2 entonces la matrices son de tamaño 2 x 2).
 * 
 * Las dos primeras matrices se sumaran y su resultado se almacenara en la tercera matriz.
*/
void matrix_addition( const vector<vector<unsigned long long>>& matrix1, const vector<vector<unsigned long long>>& matrix2, vector<vector<unsigned long long>>& matrix3, int n )
{
    /**
     * Bucle que realiza la suma de los elementos de la primera matriz
     * con los de la segunda matriz y va rellenando la tercera matriz
     * con los resultados de dichas operaciones.
    */
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            matrix3[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

/**
 * Funcion que realiza la resta de matrices.
 * 
 * La Funcion recibe tres matrices cuadradas y un entero que indicara el tamaño de la matriz 
 * (si el entero es 2 entonces la matrices son de tamaño 2 x 2).
 * 
 * Las dos primeras matrices se restaran y su resultado se almacenara en la tercera matriz.
*/
void matrix_subtraction( const vector<vector<unsigned long long>>& matrix1, const vector<vector<unsigned long long>>& matrix2, vector<vector<unsigned long long>>& matrix3, int n )
{
    /**
     * Bucle que realiza la resta de los elementos de la primera matriz
     * con los de la segunda matriz y va rellenando la tercera matriz
     * con los resultados de dichas operaciones.
    */
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            matrix3[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
}

/**
 * Funcion que realiza la multiplicacion de matrices.
 * 
 * La Funcion recibe tres matrices cuadradas y un entero que indicara el tamaño de la matriz 
 * (si el entero es 2 entonces las matrices son de tamaño 2 x 2).
 * 
 * Las dos primeras matrices se multiplicaran y su resultado se almacenara en la tercera matriz.
*/
void matrix_multiplication( const vector<vector<unsigned long long>>& matrix1, const vector<vector<unsigned long long>>& matrix2, vector<vector<unsigned long long>>& matrix3, int n )
{
    for ( int i = 0; i < n; ++i )
    {
        for ( int j = 0; j < n; j += 4 )
        {
            matrix3[i][j] = 0;
            matrix3[i][j + 1] = 0;
            matrix3[i][j + 2] = 0;
            matrix3[i][j + 3] = 0;

            for ( int k = 0; k < n; ++k )
            {
                matrix3[i][j] += matrix1[i][k] * matrix2[k][j];
                matrix3[i][j + 1] += matrix1[i][k] * matrix2[k][j + 1];
                matrix3[i][j + 2] += matrix1[i][k] * matrix2[k][j + 2];
                matrix3[i][j + 3] += matrix1[i][k] * matrix2[k][j + 3];
            }
        }
    }
}


/**
 * Funcion que realiza el Algoritmo de Strassen.
 * 
 * La Funcion recibe tres matrices cuadradas, un entero que indicara el tamaño de la matriz 
 * (si el entero es 2 entonces las matrices son de tamaño 2 x 2) y otro entero que nos ayuda 
 * a verificar si es necesario aplicar la multiplicacion de matrices por medio del Algoritmo 
 * de Strassen o simplemente aplicar la multiplicacion de matrices por medio de la funcion 
 * anterior.
*/
void strassen( const vector<vector<unsigned long long>> &A, const vector<vector<unsigned long long>> &B, vector<vector<unsigned long long>> &C, int n, int t )
{
    /**
     * Este condicional nos indicara si procedemos a ejecutar la multiplicacion
     * de matrices por medio de la funcion matrix_multiplication o si se continua
     * la multiplicacion de matrices por medio del Algoritmo de Strassen.
    */
    if ( n <= t )
    {
        matrix_multiplication( A, B, C, n );
        return;
    }

    // Calculo el nuevo tamaño de las matrices.
    int halfSize = n / 2;

    /**
     * Creacion de las submatrices A11, A12, A21, A22, B11, B12, B21, B22, C11, C12, C21, C22.
     * Donde A11, A12, A21 y A22 son submatrices de A; B11, B12, B21, B22 son submatrices de B
     * y C11, C12, C21, C22 son submatrices de C.
    */
    vector<vector<unsigned long long>> A11( halfSize, vector<unsigned long long>(halfSize) );
    vector<vector<unsigned long long>> A12( halfSize, vector<unsigned long long>(halfSize) );
    vector<vector<unsigned long long>> A21( halfSize, vector<unsigned long long>(halfSize) );
    vector<vector<unsigned long long>> A22( halfSize, vector<unsigned long long>(halfSize) );

    vector<vector<unsigned long long>> B11( halfSize, vector<unsigned long long>(halfSize) );
    vector<vector<unsigned long long>> B12( halfSize, vector<unsigned long long>(halfSize) );
    vector<vector<unsigned long long>> B21( halfSize, vector<unsigned long long>(halfSize) );
    vector<vector<unsigned long long>> B22( halfSize, vector<unsigned long long>(halfSize) );

    vector<vector<unsigned long long>> C11( halfSize, vector<unsigned long long>(halfSize) );
    vector<vector<unsigned long long>> C12( halfSize, vector<unsigned long long>(halfSize) );
    vector<vector<unsigned long long>> C21( halfSize, vector<unsigned long long>(halfSize) );
    vector<vector<unsigned long long>> C22( halfSize, vector<unsigned long long>(halfSize) );

    /**
     * Realizamos la division de las matrices A y B en 4 submatrices cada una y las rellenamos.
    */
    int i, j;
    for ( i = 0; i < halfSize; i++ )
    {
        for ( j = 0; j < halfSize; j++ )
        {
         
            A11[i][j] = A[i][j];         
            A12[i][j] = A[i][j + halfSize];        
            A21[i][j] = A[i + halfSize][j];
            A22[i][j] = A[i + halfSize][j + halfSize];
            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + halfSize];
            B21[i][j] = B[i + halfSize][j];
            B22[i][j] = B[i + halfSize][j + halfSize];
        }
    }

    // Creamos P1, P2, P3, P4, P5, P6, P7, R1, R2.
    vector<vector<unsigned long long>> P1( halfSize, vector<unsigned long long>(halfSize) );
    vector<vector<unsigned long long>> P2( halfSize, vector<unsigned long long>(halfSize) );
    vector<vector<unsigned long long>> P3( halfSize, vector<unsigned long long>(halfSize) );
    vector<vector<unsigned long long>> P4( halfSize, vector<unsigned long long>(halfSize) );
    vector<vector<unsigned long long>> P5( halfSize, vector<unsigned long long>(halfSize) );
    vector<vector<unsigned long long>> P6( halfSize, vector<unsigned long long>(halfSize) );
    vector<vector<unsigned long long>> P7( halfSize, vector<unsigned long long>(halfSize) );
    vector<vector<unsigned long long>> R1( halfSize, vector<unsigned long long>(halfSize) );
    vector<vector<unsigned long long>> R2( halfSize, vector<unsigned long long>(halfSize) );

    // Calculo de P1 = (A11 + A22) * (B11 + B22)
    matrix_addition( A11, A22, R1, halfSize );
    matrix_addition( B11, B22, R2, halfSize );
    strassen( R1, R2, P1, halfSize, t );

    // Calculo de P2 = (A21 + A22) * B11
    matrix_addition( A21, A22, R1, halfSize );
    strassen( R1, B11, P2, halfSize, t );

    // Calculo de P3 = A11 * (B12 - B22)
    matrix_subtraction( B12, B22, R2, halfSize );
    strassen( A11, R2, P3, halfSize, t );

    // Calculo de P4 = A22 * (B21 - B11)
    matrix_subtraction( B21, B11, R2, halfSize );
    strassen( A22, R2, P4, halfSize, t );

    // Calculo de P5 = (A11 + A12) * B22
    matrix_addition( A11, A12, R1, halfSize );
    strassen( R1, B22, P5, halfSize, t );

    // Calculo de P6 = (A21 - A11) * (B11 + B12)
    matrix_subtraction( A21, A11, R1, halfSize );
    matrix_addition( B11, B12, R2, halfSize );
    strassen( R1, R2, P6, halfSize, t );

    // Calculo de P7 = (A12 - A22) * (B21 + B22)
    matrix_subtraction( A12, A22, R1, halfSize );
    matrix_addition( B21, B22, R2, halfSize );
    strassen( R1, R2, P7, halfSize, t );

    // Calculo de C12 = P3 + P5
    matrix_addition( P3, P5, C12, halfSize );

    // Calculo de C21 = P2 + P4
    matrix_addition( P2, P4, C21, halfSize );

    // Calculo de C11 = P1 + P4 - P5 + P7
    matrix_addition( P1, P4, R1, halfSize );
    matrix_addition( R1, P7, R2, halfSize );
    matrix_subtraction( R2, P5, C11, halfSize );
    
    // Calculo de C22 = P1 - P2 + P3 + P6
    matrix_addition( P1, P3, R1, halfSize );
    matrix_addition( R1, P6, R2, halfSize );
    matrix_subtraction( R2, P2, C22, halfSize );

    // Combinamos las submatrices C11, C12, C21 y C22 en la matriz C.
    for ( i = 0; i < halfSize; i++ )
    {
        for ( j = 0; j < halfSize; j++ )
        {
            C[i][j] = C11[i][j];
            C[i][j + halfSize] = C12[i][j];
            C[i + halfSize][j] = C21[i][j];
            C[i + halfSize][j + halfSize] = C22[i][j];
        }
    }
}

int main()
{
    // Solicito el input del programa.
    unsigned int n, i, j, d1, P1, r1, m1, d2, P2, r2, m2;
    cin >> n >> P1 >> d1 >> r1 >> m1 >> P2 >> d2 >> r2 >> m2;

    
    // Creo las matrices A, B y C de tamaño n x n.
    vector<vector<unsigned int>> A( n, vector<unsigned int>( n ) );
    vector<vector<unsigned int>> B( n, vector<unsigned int>( n ) );
    vector<vector<unsigned long long>> C( n, vector<unsigned long long>( n ) );

    // Creo un vector y lo inicializo con tamaño n y todos sus elementos con cero.
    vector<unsigned long long> V( n, 0 );

    // Se rellenan las matrices A y B.
    for ( i = 0; i < n; ++i )
    {
        for ( j = 0; j < n; ++j )
        {
            d1 = d1 * P1 + r1;
            d2 = d2 * P2 + r2;
            A[i][j] = d1 >> (32 - m1);
            B[i][j] = d2 >> (32 - m2);
        }
    }

    /**
     * Aplico la funcion pow_two y su resultado lo almaceno en una nueva variable llamada "nnew".
     * Creo tres matrices llamadas Al, Bl y Cl.
    */
    int nnew = pow_two( n );
    vector<unsigned long long> vec( nnew );
    vector<vector<unsigned long long>> Al( nnew, vec ), Bl( nnew, vec ), Cl( nnew, vec );

    // Copiamos los elementos de las matrices A y B en las matrices Al y Bl.
    for ( i = 0; i < n; ++i )
    {
        for ( j = 0; j < n; ++j )
        {
            Al[i][j] = static_cast<unsigned long long>(A[i][j]);
            Bl[i][j] = static_cast<unsigned long long>(B[i][j]);
        }
    }

    // Aplico la funcion de strassen.
    strassen( Al, Bl, Cl, nnew, 50 );

    // Copiamos los elementos de Cl en la matriz C.
    for ( i = 0; i < n; ++i )
    {
        for ( j = 0; j < n; ++j )
        {
            C[i][j] = Cl[i][j];
        }
    }

    for ( i = 0; i < n; ++i )
    {
        V[i] = 0;
        for ( j = 0; j < n; ++j )
        {
            V[i] ^= C[i][j];
        }
    }

    // Output:
    for ( auto& e : V )
    {
        cout << e << " ";
    }
    cout << endl;

    return 0;
}