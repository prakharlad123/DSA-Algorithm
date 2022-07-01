long long  multiplyTwoLists (Node* l1, Node* l2)
{
  long long num1 = 0;
  long long num2 = 0;
  long long mod = 1000000007;
  
  Node *p = l1;
  
  while(p != NULL) {
      num1 = (num1 * 10) + p->data;
      num1 = num1 % mod;
      p = p->next;
  }
  
  p = l2;
  
  while(p != NULL) {
      num2 = (num2 * 10) + p->data;
      num2 = num2 % mod;
      p = p->next;
  }
  
  return (num1 * num2) % mod;
}
