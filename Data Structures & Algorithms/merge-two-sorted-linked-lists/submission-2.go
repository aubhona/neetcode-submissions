/*
 * @lc app=leetcode id=21 lang=golang
 *
 * [21] Merge Two Sorted Lists
*/

// @lc code=start
func mergeTwoLists(list1 *ListNode, list2 *ListNode) *ListNode {
    var head, tail  *ListNode

	for list1 != nil || list2 != nil {
		var newNode *ListNode

		if list1 == nil {
			newNode = &ListNode{
				Val: list2.Val,
			}
			list2 = list2.Next
		} else if list2 == nil {
			newNode = &ListNode{
				Val: list1.Val,
			}
			list1 = list1.Next
		} else if list1.Val < list2.Val {
			newNode = &ListNode{
				Val: list1.Val,
			}
			list1 = list1.Next
		} else {
			newNode = &ListNode{
				Val: list2.Val,
			}
			list2 = list2.Next
		}

		if head == nil {
			head = newNode
			tail = newNode
		} else {
			tail.Next = newNode
			tail = newNode
		}
	}

	return head
}
// @lc code=end
