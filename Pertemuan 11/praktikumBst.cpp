#include <iostream>
using namespace std;

struct BstNode {
	int data;
	BstNode* left;
	BstNode* right;
};

//membuat Node Baru
BstNode* GetNewNode(int data) {
	BstNode* newNode = new BstNode();
	newNode->data = data;
	newNode->left = newNode->right = NULL;
	return newNode;
}

//Memasukan data ke BST
BstNode* Insert(BstNode* root, int data) {
	if (root == NULL) {
		root = GetNewNode(data);
	}
	//jika data yang akan disisipkan lebih sedikit, sisipkan di subpohon kiri
	else if (data <= root->data) {
		root->left = Insert(root->left, data);
	}
	//lainnya, masukkan di subpohon kanan
	else {
		root->right = Insert(root->right, data);
	}
	return root;
}

//pencarian element di BST
bool search(BstNode* root, int data) {
	if (root == NULL) {
		return false;
	}
	else if (root->data == data) {
		return true;
	}
	else if (data <= root->data) {
		return search(root->left, data);
	}
	else {
		return search(root->right, data);
	}
}

//Tranverse
void printInorder(BstNode* root) {
	if (root == NULL)
		return;
	printInorder(root->left);
	cout << root->data << " ";
	printInorder(root->right);
}



int main() {
	cout << "NAMA: WIJAYANTO AGUNG WIBOWO\n";
	cout << "NIM: 22.11.4552\n\n";
	cout << "\t== BINARY SEARCH TREE==\n\n";
	BstNode* root = NULL; //membuat tree kosong
	//penambahan node pada tree
	root = Insert(root, 15);
	root = Insert(root, 10);
	root = Insert(root, 20);
	root = Insert(root, 25);
	root = Insert(root, 8);
	root = Insert(root, 12);

	printf("Urutan Data Tree secara Inorder");
	printf("\n================================\n");
	printInorder(root);


	int number;
	cout << "\n\nMasukan nomor yang dicari : ";
	cin >> number;
	//menampilkan hasil pencarian
	if (search(root, number) == true) cout << "\nData Ditemukan\n";
	else cout << "Data Tidak Ditemukan\n";
}