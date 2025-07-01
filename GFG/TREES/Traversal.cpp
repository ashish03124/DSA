//
// Created by Agaru on 7/1/2025.
//
/*
 *TRAVERSAL TECHNIQUE
 *          DSF->
 *                     [1]
 *                    /    \
 *               [2]         [3]
 *              /   \       /  \
 *           [4]    [5]   [6]   [7]
 *
 *=================================================================
 *                                      [IN]
 *         | Inorder Traversal ~~~ Left Root Right
 *         --> [ 4->2->5 ] [ ->1 ] [ ->6->3->7 ]
 *                  left      root      right
 *
 * ================================================================
 *                                   [PRE]
 *         | Pre-Order Traversal ~~~ Root  Left Right
 *         -->[ ->1 ] [ 2->4->5-> ] [ ->3->6->7 ]
 *             root      left            right
 *
 *==================================================================
 *                                               [POST]
 *         |Post-Order Traversal ~~~ Left  Right  Root
 *         -->[ 4->5->2 ] [ 6->7->3 ] [ ->1 ]
 *             Left      Right            Root
 *
 *TRAVERSAL TECHNIQUE
 *          BSF->
 *                     [1]
 *                    /    \
 *               [2]         [3]
 *              /   \       /  \
 *           [4]    [5]   [6]   [7]