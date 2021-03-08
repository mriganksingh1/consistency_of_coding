#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
  int data;
  Node *next;
  Node(int data)
  {
    this->data = data;
    this->next = NULL;
  }
};

Node *reverse(Node *head)
{
  Node *p = NULL;
  Node *c = head;
  while (c != NULL)
  {
    Node *t = c->next;
    c->next = p;
    p = c;
    c = t;
  }
  return p;
}
Node *sm(Node *head1, Node *head2)
{
  if (head1 == NULL && head2 == NULL)
  {
    return NULL;
  }
  if (head1 == NULL)
  {
    return head2;
  }
  if (head2 == NULL)
  {
    return head1;
  }
  Node *head;
  if (head1->data <= head2->data)
  {
    head = head1;
    head->next = sm(head1->next, head2);
  }
  else
  {
    head = head2;
    head->next = sm(head1, head2->next);
  }
  return head;
}
void sort(Node **head)
{
  Node *head1 = *head;
  Node *head2;
  Node *p = *head;
  head2 = p->next;
  while (p->next != NULL)
  {
    Node *t = p->next;
    p->next = p->next->next;
    p = t;
  }
  head2 = reverse(head2);
  *head = sm(head1, head2);
}

void print_linked_list(Node *head)
{
  Node *temp = head;
  while (temp != NULL)
  {
    cout << temp->data << " ";
    temp = temp->next;
  }
}

int main()
{
  Node *head = NULL;
  Node *temp = NULL;
  int input;
  cin >> input;
  while (input != -1)
  {
    Node *newnode = new Node(input);
    if (head == NULL)
    {
      head = newnode;
      temp = head;
    }
    else
    {
      temp->next = newnode;
      temp = temp->next;
    }
    cin >> input;
  }
  print_linked_list(head);
  sort(&head);
  cout << endl;
  print_linked_list(head);
}