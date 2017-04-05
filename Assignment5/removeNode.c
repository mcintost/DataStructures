struct AVLNode *_removeNode(struct AVLNode *cur, TYPE val{
	struct AVLNode *temp;
	
	if(val == cur->val)
	{
		if(cur->rght != 0)
		{
			cur->val = _leftMost(cur->rght);
			cur->rght =_removeLeftmost(cur->rght);
			return _balance(cur);
		}
		else {
			temp = cur->left;
			free(cur);
			return temp;
		}
	}
	else if(val < cur->val)
		cur->left = _removeNode(cur->left, val);
	else cur->rght = _removeNode(cur->rght, val);
		return _balance(cur);
} 