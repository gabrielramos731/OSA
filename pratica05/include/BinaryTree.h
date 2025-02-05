#ifndef BINARYTREE_H
#define BINARYTREE_H

class No {
public:
    long int chave;
    long posicao;
    No* esquerda;
    No* direita;

    No(long int k, long pos) : chave(k), posicao(pos), esquerda(nullptr), direita(nullptr) {}
};

class BinaryTree {
private:
    No* raiz;

    void insereNo(No*& no, long int chave, long posicao);
    long buscaNo(No* no, long int chave) const;
    void liberaArvore(No* no);

public:
    BinaryTree();

    void insere(long int chave, long posicao);
    long busca(long int chave) const;
};

#endif