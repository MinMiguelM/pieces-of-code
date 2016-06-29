from Node import *

class BST(object):
    def __init__(self, root):
        self.root = Node(root)

    def insert(self, new_val):
        node = self.root
        while node:
            if new_val > node.value:
                if not node.right:
                    node.right = Node(new_val)
                    return
                else:
                    node = node.right
            else:
                if not node.left:
                    node.left = Node(new_val)
                    return
                else:
                    node = node.left

    def search(self, find_val):
        node = self.root
        while node:
            if node.value < find_val:
                node = node.right
            elif find_val < node.value:
                node = node.left
            else:
                return True
        return False
    
# Set up tree
tree = BST(4)

# Insert elements
tree.insert(2)
tree.insert(1)
tree.insert(3)
tree.insert(5)

# Check search
# Should be True
print tree.search(4)
# Should be False
print tree.search(6)