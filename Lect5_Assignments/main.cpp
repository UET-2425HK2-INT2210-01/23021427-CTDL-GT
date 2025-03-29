// Bao gồm thư viện cần thiết
#include <iostream>
using namespace std;

// Cấu trúc một nút trong cây tổng quát
struct Node {
    int data;  // Giá trị của nút
    Node* firstChild;  // Con đầu tiên
    Node* nextSiblings;  // Anh chị em cùng cấp

    // Constructor khởi tạo một nút mới
    Node(int x) {
        data = x;
        firstChild = nullptr;
        nextSiblings = nullptr;
    }
};

class Tree {
public:
    Node* root = nullptr;  // Gốc của cây

    // Tìm cha của một nút dựa trên giá trị
    Node* findParent(Node* root, int value) {
        if(root == nullptr) return nullptr;  // Trả về nullptr nếu cây rỗng
        if(root->data == value) return root;  // Trả về nút nếu tìm thấy giá trị
        
        // Tìm kiếm trong cây con
        Node* found = findParent(root->firstChild, value);
        if(found) return found;
        
        // Nếu không tìm thấy trong cây con, tìm trong anh chị em
        return findParent(root->nextSiblings, value);
    }

    // Hàm tạo cây bằng cách thêm nút con vào nút cha
    void makeTree(int x, int y) {
        if(root == nullptr) {
            root = new Node(x);  // Nếu cây rỗng, tạo gốc mới
        }
        
        Node* parent = findParent(root, x);  // Tìm cha
        if(!parent) return;  // Nếu không tìm thấy, thoát

        Node* newChild = new Node(y);  // Tạo nút con mới

        if(parent->firstChild == nullptr) {
            parent->firstChild = newChild;  // Nếu chưa có con, gán trực tiếp
        } else {
            // Duyệt đến anh em cuối cùng để thêm con mới
            Node* sibling = parent->firstChild;
            while(sibling->nextSiblings != nullptr) {
                sibling = sibling->nextSiblings;
            }
            sibling->nextSiblings = newChild;
        }
    }

    // Tính chiều cao của cây
    int findHeight(Node* root) {
        if(root == nullptr) return -1;  // Cây rỗng có chiều cao -1

        int maxHeight = -1;  // Biến lưu chiều cao lớn nhất
        Node* child = root->firstChild;

        while(child) {
            maxHeight = max(maxHeight, findHeight(child));  // Tìm chiều cao lớn nhất
            child = child->nextSiblings;
        }
        return 1 + maxHeight;  // Chiều cao bằng 1 + chiều cao lớn nhất của con
    }

    // In chiều cao của cây
    void printHeight() {
        cout << findHeight(root) << endl;
    }

    // Duyệt cây theo preOrder
    void preOrder(Node* root) {
        if(root == nullptr) return;
        cout << root->data << " ";  // In giá trị nút hiện tại
        preOrder(root->firstChild);  // Duyệt cây con
        preOrder(root->nextSiblings);  // Duyệt anh chị em
    }

    // In preOrder
    void printPreOrder() {
        preOrder(root);
        cout << endl;
    }

    // Duyệt cây theo postOrder
    void postOrder(Node* root) {
        if (root == nullptr) return;
        postOrder(root->firstChild);  // Duyệt toàn bộ cây con trước
        cout << root->data << " ";  // In nút hiện tại
        postOrder(root->nextSiblings);  // Duyệt anh em
    }

    // In postOrder
    void printPostOrder() {
        postOrder(root);
        cout << endl;
    }

    // Kiểm tra cây nhị phân
    bool isBinaryTree(Node* root) {
        if(root == nullptr) return true;  // Cây rỗng là nhị phân

        int count = 0;  // Biến đếm số con
        Node* child = root->firstChild;

        while(child) {
            count++;
            if (count > 2) return false;  // Nếu có hơn 2 con thì không phải cây nhị phân
            if (!isBinaryTree(child)) return false;  // Đệ quy kiểm tra
            child = child->nextSiblings;
        }
        return true;
    }

    // Kiểm tra và trả về kết quả cây nhị phân
    bool checkBinaryTree() {
        return isBinaryTree(root);
    }

    // Duyệt theo Inorder nếu là cây nhị phân
    void inOrder(Node* root) {
        if(root == nullptr) return;
        if(root->firstChild) inOrder(root->firstChild);  // Duyệt trái trước
        cout << root->data << " ";  // In giá trị nút
        if(root->firstChild && root->firstChild->nextSiblings)  // Duyệt phải nếu có
            inOrder(root->firstChild->nextSiblings);
    }

    // In inOrder nếu là cây nhị phân
    void printInOrder() {
        if (checkBinaryTree()) {
            inOrder(root);
            cout << endl;
        } else {
            cout << "NOT BINARY TREE" << endl;
        }
    }
};

int main() {
    int n, m;
    cin >> n >> m;  // Nhập số nút và số cạnh

    Tree myTree;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        myTree.makeTree(x, y);
    }

    myTree.printHeight();  // In chiều cao của cây
    myTree.printPreOrder();  // In preOrder
    myTree.printPostOrder();  // In postOrder
    myTree.printInOrder();  // Kiểm tra và in inOrder nếu là cây nhị phân

    return 0;
}