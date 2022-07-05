vector<int> leftView(Node *root) {
   vector<int> ans;
   
   if(root == NULL) {
       return ans;
   }
   
   map<int, int> mp;
   queue<pair<Node*, int>> q;
   
   q.push({root, 0});
   
   while(!q.empty()) {
       auto it = q.front();
       q.pop();
       
       if(it.first->left) {
           q.push({it.first->left, it.second + 1});
       }
       
       if(it.first->right) {
           q.push({it.first->right, it.second + 1});
       }
       
       if(mp.find(it.second) == mp.end()) {
           mp[it.second] = it.first->data;
       }
    }
    
    for(auto it : mp) {
        ans.push_back(it.second);
    }
    
    return ans;
}
