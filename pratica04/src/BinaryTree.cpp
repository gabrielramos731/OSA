#include "../include/BinaryTree.h"

BinaryTree::BinaryTree() : raiz(nullptr) {}

void BinaryTree::insereNo(No*& no, long int chave, long posicao) {
    if (!no) {
        no = new No(chave, posicao);
    } else if (chave < no->chave) {
        insereNo(no->esquerda, chave, posicao);
    } else if (chave > no->chave) {
        insereNo(no->direita, chave, posicao);
    }
}

long BinaryTree::buscaNo(No* no, long int chave) const {
    if (!no) {
        return -1;
    }
    if (chave == no->chave) {
        return no->posicao;
    }
    if (chave < no->chave) {
        return buscaNo(no->esquerda, chave);
    }
    return buscaNo(no->direita, chave);
}

void BinaryTree::insere(long int chave, long posicao) {
    insereNo(raiz, chave, posicao);
}

long BinaryTree::busca(long int chave) const {
    return buscaNo(raiz, chave);
}