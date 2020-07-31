#include <iostream>
#include <fstream>
using namespace std;

struct Node{
int data;
int key = data;
Node* next;

Node();
Node(int data);
Node(const Node& node);
int CompareWith(const Node& node);
int GetKey();
void ReadFromFile(ifstream &infile);
void WriteToFile(ofstream &ofile);
void print();
};

Node::Node():data(0), next(NULL)
{

}

Node::Node(int data):data(data), next(NULL)
{

}

Node::Node(const Node& node):data(node.data), next(node.next)
{

}

int Node::CompareWith(const Node& node)
{
  if(this->key > node.key) return 1;
  if(this->key == node.key) return 0;
  if(this->key < node.key) return -1;
}

int Node::GetKey()
{
  return key;
}

void Node::ReadFromFile(ifstream &infile)
{
  infile.read((char*) &this->data, sizeof(this->data));
}

void Node::WriteToFile(ofstream &ofile)
{
  ofile.write((char*) &this->data, sizeof(this->data));
}

void Node::print()
{
  cout<<this->data;
}

/*#include <iostream>
#include <fstream>
using namespace std;

struct Node{
int data;
int key = data;
Node* next;

Node();
Node(int data);
Node(const Node& node);
int CompareWith(const Node& node);
int GetKey();
void ReadFromFile(ifstream &infile);
void WriteToFile(ofstream &ofile);
void print();
};

Node::Node():data(0), next(NULL)
{

}

Node::Node(int data):data(data), next(NULL)
{

}

Node::Node(const Node& node):data(node.data), next(node.next)
{

}

int Node::CompareWith(const Node& node)
{
  if(this->key > node.key) return 1;
  if(this->key == node.key) return 0;
  if(this->key < node.key) return -1;
}

int Node::GetKey()
{
  return key;
}

void Node::ReadFromFile(ifstream &infile)
{
  infile.read((char*) &this->data, sizeof(this->data));
}

void Node::WriteToFile(ofstream &ofile)
{
  ofile.write((char*)&this->data, sizeof(this->data));
}

void Node::print()
{
  cout<<this->data;
}
*/
