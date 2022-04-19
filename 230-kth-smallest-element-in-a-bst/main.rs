// Definition for a binary tree node.
// #[derive(Debug, PartialEq, Eq)]
// pub struct TreeNode {
//   pub val: i32,
//   pub left: Option<Rc<RefCell<TreeNode>>>,
//   pub right: Option<Rc<RefCell<TreeNode>>>,
// }
// 
// impl TreeNode {
//   #[inline]
//   pub fn new(val: i32) -> Self {
//     TreeNode {
//       val,
//       left: None,
//       right: None
//     }
//   }
// }
use std::rc::Rc;
use std::cell::RefCell;

impl Solution {
  pub fn kth_smallest(root: Option<Rc<RefCell<TreeNode>>>, k: i32) -> i32 {
    fn helper(node: Option<Rc<RefCell<TreeNode>>>, k: i32) -> (Option<i32>, i32) {
      match node {
        Some(node) => {
          let n = node.borrow();
          match helper(n.left.clone(), k) {
            (None, count) => {
              match count {
                1 => (Some(n.val), 0),
                _ => helper(n.right.clone(), count - 1)
              }
            },
            (res, _) => (res, 0)
          }
        },
        None => (None, k)
      }
    }

    helper(root, k).0.unwrap()
  }
}