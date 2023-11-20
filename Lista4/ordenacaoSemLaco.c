void ordena(int *v, int n) {
    // Caso base: se há apenas um elemento ou nenhum, o array já está ordenado
    if (n <= 1) {
        return;
    }

    // Chama a função ordena recursivamente para n-1 elementos
    ordena(v, n - 1);

    // Insere o último elemento na posição correta
    int key = v[n - 1];
    int j = n - 2;

    // Move os elementos maiores que key para uma posição à frente
    while (j >= 0 && v[j] > key) {
        v[j + 1] = v[j];
        j--;
    }

    // Coloca key na posição correta
    v[j + 1] = key;
}
