

---

### What is Vector Programming?

Vector programming is a technique that involves using data structures called **vectors** (or **arrays**) to store and manipulate **sets of elements of the same type** in an organized and efficient way.

### Structure of a Vector

A vector is a **sequence of contiguous memory locations**, where each position stores a value. All elements in the vector must have the **same data type** (e.g., all integers, all floats, all characters, etc.). The number of elements the vector can hold is called its **size** or **capacity**.

Each element is identified by an **index** or **position**, which allows direct access to its value. Typically, the index starts at 0 and goes up to N-1, where N is the size of the vector.

Example of a vector with 5 positions:

```
[0] → 10  
[1] → 20  
[2] → 30  
[3] → 40  
[4] → 50
```

### How Do We Use Vectors in Programming?

1. **Declaration**: We define the vector and its size.

   * Example in C: `int grades[30];`

2. **Assignment**: We store values in specific positions.

   * `grades[0] = 10;`

3. **Access**: We read values from specific positions.

   * `printf("%d", grades[0]);`

4. **Traversal**: We use loops (`for`, `while`) to access all elements.

   * Example:

     ```c
     for (int i = 0; i < 30; i++) {
         printf("%d\n", grades[i]);
     }
     ```

### Advantages of Vector Programming

✅ Efficient organization of large amounts of data.
✅ Fast and direct access to elements via index.
✅ Facilitates the implementation of algorithms like searching, sorting, statistics, etc.

### Limitations

❌ The size is usually fixed, defined at the time of declaration.
❌ Only stores data of the same type.
❌ Not ideal for cases involving frequent insertion and removal in intermediate positions (for that, we use lists).

### Practical Applications

* Storing students' grades.
* Processing time series data (e.g., daily temperatures).
* Manipulating images (where each pixel can be represented by a value in a vector).
* Solving mathematical and statistical problems.

### Relation to Algorithms

Many **classic algorithms** are based on vector manipulation:

* **Linear and binary search**.
* **Sorting** (Bubble Sort, QuickSort, etc.).
* **Statistical calculations** (mean, median, mode).

---

### O que é Programação de Vetores?

Programação de vetores é uma técnica que consiste em utilizar estruturas de dados chamadas **vetores** (ou arrays) para armazenar e manipular **conjuntos de elementos do mesmo tipo** de maneira organizada e eficiente.

### Estrutura do Vetor

Um vetor é uma **sequência de posições** contíguas na memória, onde cada posição armazena um valor. Todos os elementos do vetor possuem o **mesmo tipo de dado** (por exemplo, todos inteiros, todos reais, todos caracteres, etc.). A quantidade de elementos que o vetor pode armazenar é chamada de **tamanho** ou **capacidade** do vetor.

Cada elemento é identificado por um **índice** ou **posição**, que permite o acesso direto ao seu valor. Normalmente, o índice começa em 0 e vai até N-1, onde N é o tamanho do vetor.

Exemplo de vetor com 5 posições:

```
[0] → 10  
[1] → 20  
[2] → 30  
[3] → 40  
[4] → 50
```

### Como Usamos Vetores na Programação?

1. **Declaração**: Definimos o vetor e seu tamanho.

   * Exemplo em C: `int notas[30];`

2. **Atribuição**: Colocamos valores em posições específicas.

   * `notas[0] = 10;`

3. **Acesso**: Lemos valores em posições específicas.

   * `printf("%d", notas[0]);`

4. **Percorrimento**: Usamos estruturas de repetição (como `for` ou `while`) para acessar todos os elementos.

   * Exemplo:

     ```c
     for (int i = 0; i < 30; i++) {
         printf("%d\n", notas[i]);
     }
     ```

### Vantagens da Programação com Vetores

✅ Organização eficiente de grandes quantidades de dados.
✅ Acesso rápido e direto aos elementos via índice.
✅ Facilita a implementação de algoritmos como busca, ordenação, estatísticas, entre outros.

### Limitações

❌ O tamanho é fixo na maioria das linguagens, definido no momento da declaração.
❌ Só armazena dados do mesmo tipo.
❌ Não é ideal para casos que envolvem inserção e remoção frequente de elementos em posições intermediárias (para isso, usamos listas).

### Aplicações Práticas

* Armazenar notas de alunos.
* Processar séries temporais de dados (como temperaturas diárias).
* Manipular imagens (em que cada pixel pode ser representado por um valor em um vetor).
* Resolver problemas matemáticos e estatísticos.

### Relação com Algoritmos

Muitos **algoritmos clássicos** são baseados na manipulação de vetores:

* **Busca linear e binária**.
* **Ordenação** (Bubble Sort, QuickSort, etc.).
* **Cálculos estatísticos** (média, mediana, moda).

---
