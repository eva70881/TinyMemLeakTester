#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A definition of BST node
struct node{
  void* pointer;
  int line_number;
  long long size;
  char* file;
  char* function;
  struct node *left, *right;
};

// BST root node
static struct node* root_node = NULL;

// Count of BST node
static int node_count = 0;

// Create a new node for BST
struct node* create_new_node(void* pointer, const char* file, int line, const char* func, long long size)
{
  struct node *tmp = (struct node*)malloc(sizeof(struct node));
  tmp->pointer = pointer;
  tmp->line_number = line;
  tmp->size = size;
  tmp->file = (char*) malloc(sizeof(char) * (strlen(file) + 1));
  sprintf(tmp->file, "%s", file);
  tmp->function = (char*) malloc(sizeof(char) * (strlen(func) +1 ));
  sprintf(tmp->function, "%s", func);
  tmp->left = NULL;
  tmp->right = NULL;
  return tmp;
}

// Search a node from the BST
struct node* search_node(struct node* root, void* pointer)
{
  if(root == NULL)
  {
    return NULL;
  }

  if(root->pointer == pointer)
  {
    return root;
  }

  if(root->pointer < pointer)
  {
    return search_node(root->right, pointer);
  }

  return search_node(root->left, pointer);
}

// Insert a new node for BST
struct node* insert_new_node(struct node* root, void* pointer, const char* file, int line, const char* func, long long size)
{
  struct node *tmp = create_new_node(pointer, file, line, func, size);

  if(root == NULL)
  {
    return tmp;
  }

  if(pointer < root->pointer)
  {
    root->left = insert_new_node(root->left, pointer, file, line, func, size);
  }
  else if(pointer > root->pointer)
  {
    root->right = insert_new_node(root->right, pointer, file, line, func, size);
  }

  return root;
}

// Find the minimal node from the BST
struct node* get_minimal_node(struct node* root)
{
  struct node* current_node = root;
  while(current_node->left != NULL)
  {
    current_node = current_node->left;
  }

  return current_node;
}

// Delete the node from the BST
struct node* delete_node(struct node* root, void* pointer)
{
  if(root == NULL)
  {
    return NULL;
  }

  if(pointer < root->pointer)
  {
    root->left = delete_node(root->left, pointer);
  }
  else if(pointer > root->pointer)
  {
    root->right = delete_node(root->right, pointer);
  }
  else
  {
    if(root->left == NULL)
    {
      struct node *tmp = root->right;
      free(root->file);
      free(root->function);
      free(root);
      return tmp;
    }
    else if(root->right == NULL)
    {
      struct node *tmp = root->left;
      free(root->file);
      free(root->function);
      free(root);
      return tmp;
    }

    struct node *tmp = get_minimal_node(root->right);
    root->pointer = tmp->pointer;
    root->right = delete_node(root->right, tmp->pointer);
  }
  return root;
}

// Traversal of BST
void traversal(struct node* root)
{
  if(root != NULL)
  {
    traversal(root->left);
    printf("| %s | %i | %s | %p | %lli | \n",
      root->file,
      root->line_number,
      root->function,
      root->pointer,
      root->size
    );
    traversal(root->right);
  }
}

// Clean all of BST
void clean_all_nodes(struct node* root)
{
  if(root != NULL)
  {
    clean_all_nodes(root->left);
    clean_all_nodes(root->right);
    free(root->file);
    free(root->function);
    free(root);
  }
}

// Log data
void memory_modify_history_log(const char* Method, const char* file, int line, const char* func, void* loc, long long size)
{
  printf("| %s | %s | %i | %s | %p | %lli | \n",
    Method,
    file,
    line,
    func,
    loc,
    size
  );
}

void* tiny_mem_leak_malloc(size_t size, const char *file, int line, const char *func)
{
  void *ptr = malloc(size);
  memory_modify_history_log("alloc  ", file, line, func, ptr, (long long)size);
  
  root_node = insert_new_node(root_node, ptr, file, line, func, size);

  node_count++;

  return ptr;
}

void* tiny_mem_leak_realloc(void* pointer, size_t size, const char *file, int line, const char *func)
{
  void *realloc_ptr = realloc(pointer, size);
  memory_modify_history_log("realloc", file, line, func, realloc_ptr, (long long)size);
  
  root_node = delete_node(root_node, pointer);
  root_node = insert_new_node(root_node, realloc_ptr, file, line, func, size);

  return realloc_ptr;
}

void tiny_mem_leak_free(void* pointer, const char *file, int line, const char *func)
{
  memory_modify_history_log("free   ", file, line, func, pointer, 0);
  free(pointer);

  root_node = delete_node(root_node, pointer);

  node_count--;
}

void Get_Result()
{
  printf("----The list of the memory location doesn't free----\n");
  printf("| File name | Line number | Function name | Pointer address | Size of alloced |\n");
  printf("| --------- | ----------- | ------------- | --------------- | --------------- |\n");
  traversal(root_node);
  printf("Number of node in list: %d\n", node_count);
  printf("------------------End of the list-------------------\n");
  clean_all_nodes(root_node);
}