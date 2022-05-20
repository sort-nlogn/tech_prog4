#include <iostream>

char select_type(){
    printf("Select type\n1 ---int\n\
2 --- char\n\
3 --- float\n\
4 --- double\n\
5 --- char*\n");
    printf(">>");
    return getchar();
}

int get_value(){ 
    int ans;
    printf("Value to find: ");
    scanf("%d", &ans);
    return ans;
}

void display_help(){
    printf("1 --- Insert element\n\
2 --- Forward traversal\n\
3 --- Backward traversal\n\
4 --- Find element\n");
}

template<typename T>
class tree{
    private:
        struct node{
            node(T data): left(nullptr), right(nullptr){
                this->data = data;
            }
            T data;
            node *left, *right;
        };

        node *root;

    public:
        tree(): root(nullptr){

        }

        void bfs(node *curr, bool forward){
            if(curr != nullptr){
                forward? bfs(curr->left, forward): bfs(curr->right, forward);
                std::cout << curr->data << " ";
                forward? bfs(curr->right, forward): bfs(curr->left, forward);
            } 
        }

        void forward_traversal(){
            bfs(root, true);
        }

        void backward_traversal(){
            bfs(root, false);
        }

        bool has_key(T key){
            node *curr = root;
            while(curr != nullptr){
                if(key == curr->data){
                    return true;
                }else if(key < curr->data){
                    curr = curr->left;
                }else{
                    curr = curr->right;
                }
            }
            return false;
        }

        void insert(T data){
            node *curr = root;
            if(curr == nullptr){
                root = new node(data);
                return;
            }

            while(curr != nullptr){
                if(data < curr->data){
                    if(curr->left == nullptr){
                        curr->left = new node(data);
                        break;
                    }else{
                        curr = curr->left;
                    }
                }else{
                    if(curr->right == nullptr){
                        curr->right = new node(data);
                        break;
                    }else{
                        curr = curr->right;
                    }
                }
            }
        }
};

template<typename T>
void execute(tree<T> t){
    display_help();
     while(1){
        char c = getchar();
        if(c == '\n')
            printf(">>");
        if(c == '1'){
            t.insert((T)get_value());
        }else if(c == '2'){
            t.forward_traversal();
            printf("\n");
        }else if(c == '3'){
            t.backward_traversal();
            printf("\n");
        }else if(c == '4'){
            printf("%d\n", t.has_key((T)get_value()));
        }
    }
}

int main(){
    char t = select_type();

    if(t == '1'){
        tree<int> tr;
        execute<int>(tr);
    }else if(t == '2'){
        tree<char> tr;
        execute<char>(tr);
    }else if(t == '3'){
        tree<float> tr;
        execute<float>(tr);
    }else if(t == '4'){
        tree<double> tr;
        execute<double>(tr);
    }else if(t == '5'){
        tree<char*> tr;
        execute<char*>(tr);
    }else{
        throw std::runtime_error("No such option!");
    }
    return 0;
}