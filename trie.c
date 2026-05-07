#include <stdio.h>
#include <stdlib.h>

#define ALPHABET_SIZE 26

// Trie düğümü yapısı
typedef struct TrieNode {
    struct TrieNode* children[ALPHABET_SIZE]; // 26 harf için bağlantılar
    int isEndOfWord; // Kelimenin sonunu işaretler
} TrieNode;

// Yeni düğüm oluşturma fonksiyonu
TrieNode* newNode() {
    TrieNode* node = (TrieNode*) malloc(sizeof(TrieNode));
    node->isEndOfWord = 0;
    for (int i = 0; i < ALPHABET_SIZE; i++)
        node->children[i] = NULL;
    return node;
}

// Kelime ekleme fonksiyonu
void insert(TrieNode* root, char* key) {
    TrieNode* temp = root;
    for (int i = 0; key[i] != '\0'; i++) {
        int index = key[i] - 'a'; // Harfi indekse çevir
        if (temp->children[index] == NULL)
            temp->children[index] = newNode(); // Yoksa yeni düğüm oluştur
        temp = temp->children[index];
    }
    temp->isEndOfWord = 1; // Kelime sonunu işaretle
}

// Kelime arama fonksiyonu
int search(TrieNode* root, char* key) {
    TrieNode* temp = root;
    for (int i = 0; key[i] != '\0'; i++) {
        int index = key[i] - 'a';
        if (temp->children[index] == NULL)
            return 0; // Harf yoksa kelime bulunamadı
        temp = temp->children[index];
    }
    return temp->isEndOfWord; // Kelime sonu işaretliyse bulundu
}

// Ana program
int main() {
    TrieNode* root = newNode();

    // Örnek kelimeler ekleniyor
    insert(root, "elma");
    insert(root, "armut");
    insert(root, "muz");

    // Arama testleri
    printf("%d\n", search(root, "elma"));   // 1 -> bulundu
    printf("%d\n", search(root, "limon"));  // 0 -> bulunamadı

    return 0;
}
