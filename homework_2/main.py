from dataclasses import dataclass
from typing import Optional, TypeVar

TNode = TypeVar("TNode", bound="ListNode")


@dataclass
class ListNode:
    key: int
    prev: Optional[TNode] = None
    next: Optional[TNode] = None

    def add_node(self: TNode, key: int) -> TNode:
        self.next = ListNode(key, self)
        return self.next


def reverse(head: TNode) -> TNode:
    temp = None
    cur = head

    while cur != None:
        temp = cur.prev
        cur.prev = cur.next
        cur.next = temp
        cur = cur.prev
    if temp != None:
        head = temp.prev

    return head


list_head = ListNode(9)
list_head.add_node(16).add_node(4).add_node(1)

r = reverse(list_head)
print(r)

while r != None:
    print(f'current node holds {r.key}')
    r = r.next
