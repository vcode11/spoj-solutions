class Stack:
    def __init__(self):
        self.items = []
    def is_empty(self):
        return self.items == []
    def push(self,item):
        self.items.append(item)
    def pop(self):
        return self.items.pop()
    def peek(self):
        return self.items[len(self.items) - 1]
    def size(self):
        return len(self.items)
q = int(input())
st = Stack()
for i in range(q):
    s = list(map(int,input().split()))
    if s[0] == 1:
        st.push(s[1])
    elif s[0] == 2:
        if not st.is_empty():
            st.pop()
    else:
        if st.is_empty():
            print('Empty!')
        else:
            print(st.peek())