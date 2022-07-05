vector<int> diagonal(Node *root) {
   vector<int> ans;
   
   if(root == NULL) {
       return ans;
   }
   
   map<int, vector<int>> mp;
   stack<pair<Node*, int>> st;
   
   st.push({root, 0});
   
   while(!st.empty()) {
       auto it = st.top();
       
       st.pop();
       
       int slope = it.second;
       Node *tmp = it.first;
       
       mp[slope].push_back(tmp->data);
       
       if(tmp->right) {
           st.push({tmp->right, slope+0});
       }
       
       if(tmp->left) {
           st.push({tmp->left, slope+1});
       }
   }
   
   for(auto &i : mp) {
       for(auto &j : i.second) {
           ans.push_back(j);
       }
   }
   
   return ans;
}
