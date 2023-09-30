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

int first(BstNode* root) {
	BstNode* current = root;
	while (current->left != NULL) {
		current = current->left;
	}
	return (current->data);
}

int last(BstNode* root) {
	BstNode* current = root;
	while (current->right != NULL) {
		current = current->right;
	}
	return (current->data);
}



int main() {
	cout << "NAMA: WIJAYANTO AGUNG WIBOWO\n";
	cout << "NIM: 22.11.4552\n\n";
	cout << "\t== BINARY SEARCH TREE==\n\n";
	BstNode* root = NULL;
	int menu, no;
	while (true) {
		system("cls");
		cout << "Menu:\n";
		cout << "1. Input data\n";
		cout << "2. Tampilkan Nilai Terkecil\n";
		cout << "3. Tampilkan Nilai Terbesar\n";
		cout << "4. Tampilkan Urutan Data Secara Inorder\n";
		cout << "5. Pencarian Data \n";
		cout << "6. Exit \n";
		cout << " Inputkan Menu: "; cin >> menu;
		switch (menu) {
		case 1:
			cout << "Masukan data ke node: "; cin >> no;
			root = Insert(root, no);
			break;
		case 2:
			cout << "Nilai minimum adalah : " << first(root) << endl;
			system("pause");
			break;
		case 3:
			cout << "Nilai Maksimalnya adalah : " << last(root) << endl;
			system("pause");
			break;
		case 4:
			printf("Urutan Data Tree secara Inorder");
			printf("\n================================\n");
			printInorder(root);
			system("pause");
			break;
		case 5:
			int number;
			printf("Pencarian Elemen Data");
			printf("\n================================\n");
			printf("Masukan Elemen Data Yang Dicari : ");
			cin >> number;
			if (search(root, number) == true) {
				cout << "Data Ditemukan\n";
				system("pause");
			}
			else {
				cout << "Data tidak ditemukan\n";
				system("pause");
			}
			break;
		case 6:
			exit;
		}
	}
}
