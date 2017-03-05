// ---- Program Info Start----
//FileName:     FindKthToTail.cpp
//
//Author:       Fuchen Duan
//
//Email:        slow295185031@gmail.com
//
//CreatedAt:    2017-03-05 19:01:55
// ---- Program Info End  ----

#include <iostream>

using namespace std;

struct ListNode
{
      int       m_nKey;
      ListNode* m_pNext;
      ListNode( int iVal ):m_nKey( iVal ), m_pNext( NULL ){

      }
};

int main(int argc, char *argv[])
{
    int iLength;
    cin >> iLength;

    int iNumber;
    cin>>iNumber;
    ListNode * nodeHead = new ListNode(iNumber);
    ListNode * nodeIdx = nodeHead;
    for( int i=1; i<iLength; ++i ){
        cin>>iNumber;
        ListNode * nodeTmp = new ListNode(iNumber);
        nodeIdx->m_pNext = nodeTmp;
        nodeIdx = nodeTmp;
    }
    int K;
    cin>>K;
    int iCnt = iLength - K - 1;
    nodeIdx = nodeHead;
    for( iCnt; iCnt > 0; iCnt-- ){
        nodeIdx = nodeIdx->m_pNext;
    }
    cout<<nodeIdx->m_nKey<<endl;
    return 0;
}
