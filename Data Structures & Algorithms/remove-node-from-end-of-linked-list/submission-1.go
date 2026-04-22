func removeNthFromEnd(head *ListNode, n int) *ListNode {
	forward := head
	for i := 0; i < n; i++ {
		forward = forward.Next
	}

	prev := head
	cur := head

	for forward != nil {
		prev = cur
		cur = cur.Next
		forward = forward.Next	
	}

	if cur == head {
		return head.Next
	}

	prev.Next = cur.Next

	return head
}
