func reverse(head *ListNode) *ListNode {
	var prev *ListNode

    for head != nil {
		next := head.Next
		head.Next = prev
		prev = head
		head = next
	}

	return prev
}

func reorderList(head *ListNode)  {
	if head == nil {
		return
	}

    slow := head
	fast := head

	for fast != nil && fast.Next != nil {
		slow = slow.Next
		fast = fast.Next.Next
	}

	secondHalf := reverse(slow.Next)
	slow.Next = nil

	flag := false

	for secondHalf != nil {
		if !flag {
			next := head.Next
			head.Next = secondHalf
			flag = !flag
			head = next
			continue
		}

		next := secondHalf.Next
		secondHalf.Next = head
		secondHalf = next
		flag = !flag
	}
}
