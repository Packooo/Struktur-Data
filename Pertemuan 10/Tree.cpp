/* ============================
== PROGRAM BINARY TREE ==
===============================*/

#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
struct node
{
    int data;
    struct node* left;
    struct node* right;
};

void tambahData(node** root,int data)
{
    if ((*root) == NULL) {
        struct node* newNode = (struct node*)
            malloc(sizeof(struct node)); //membuat struktur node baru
        newNode->data = data;
        newNode->left = NULL;
        newNode->right = NULL;
        (*root) = newNode;
        (*root)->left = NULL;
        (*root)->right = NULL;
        printf("Data bertambah!");
        cin.get();
    }
    //jika data yang akan dimasukkan lebih kecil daripada elemen root, maka akan diletakkan di node sebelah kiri.
    else if (data < (*root)->data)
        tambahData(&(*root)->left, data);
    //jika data yang akan dimasukkan lebih besar daripada elemen root, maka akan diletakkan di node sebelah kanan
    else if (data > (*root)->data)
        tambahData(&(*root)->right, data);
    //jika saat dicek data yang akan dimasukkan memiliki nilai yang sama dengan data pada root
    else if (data == (*root)->data)
        printf("Data sudah ada!");
        cin.get();
}

void printPreoder(struct node* node)
{
    if (node == NULL)
        return;
    //cout<< node->data << " ";
    printf("%d ", node->data);
    printPreoder(node->left);
    printPreoder(node->right);
}

void printInorder(struct node* node)
{
    if (node == NULL)
        return;
    printInorder(node->left);
    printf("%d ", node->data);
    //cout<< node->data << " ";
    printInorder(node->right);
}

void printPostorder(struct node* node)
{
    if (node == NULL)
        return;
    printPostorder(node->left);
    printPostorder(node->right);
    printf("%d ", node->data);
    //cout<< node->data << " ";
}
int main()
{
    int data,pilihan = 0;
    node* tree; //Membyat pointer tree;
    tree = NULL; //inisialisasi node pohon
    while (pilihan != 3) {
        system("cls");
        printf("\nMasukan Pilihan Menu : ");
        printf("\n1. Input Data ");
        printf("\n2. Menampilkan Kunjungan ");
        printf("\n3. Exit");
        printf("\nPilih: ");
        scanf_s("%d", &pilihan);
        switch (pilihan) {
        case 1:
            system("cls");
            printf("\nINPUT : ");
            printf("\n-------");
            printf("\nData baru : ");
            scanf_s("%d", &data);
            //panggil fungsi untuk menambah node yang berisi data pada tree
            tambahData(&tree, data);
            break;
        case 2:
            system("cls");
            printf("Wijayanto Agung Wibowo\n");
            printf("22.11.4552\n");
            printf("\n== TRAVERSAL PADA BINARY TREE ==");

            printf("\n\nKunjungan Preoreder");
            printf("\n===================\n");
            printPreoder(tree);

            printf("\n\nKunjungan Inoreder");
            printf("\n===================\n");
            printInorder(tree);

            printf("\n\nKunjungan Postorder");
            printf("\n===================\n");
            printPostorder(tree);

            system("pause");
            
            break;
        }
    }
    return 0;
}
