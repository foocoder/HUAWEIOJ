/*
 *@@@@@@@@@@ File Information Start  @@@@@@@@@@
 * @file:        PrimeCompany.cpp
 * @author:      Fuchen Duan
 * @email:       slow295185031@gmail.com
 * @github:      https://foocoder.github.com
 * @homepage:    http://foocder.github.io
 * @create at:   2017-04-05 15:56:22
 * @last update: 2017-04-05 17:40:34
 *@@@@@@@@@@ File Information Finish @@@@@@@@@@
*/

#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <cmath>
#include <stack>
#include <climits>

#ifdef DEBUG
    #include <cassert>
#endif

using namespace std;

class Graph{
    typedef
    struct Node{
        int nNodeNo = 0;
        int nWeight = 1;
        struct Node * pNextNode = NULL;

        Node( int nInputNo, int nInputWeight ):
            nNodeNo( nInputNo ),
            nWeight( nInputWeight ),
            pNextNode( NULL ){}
        Node( const Node & rhs ):
            nNodeNo(rhs.nNodeNo),
            nWeight(rhs.nWeight),
            pNextNode(NULL){}
    }Node;

    int nEdgeNum;
    int nVertexNum;
    vector<Node> vNodeVector;

    public:
    Graph(){
        cout<<"Input Number of vertex and edge:"<<endl;
        cin>>nVertexNum>>nEdgeNum;
        for( int i=0; i<nVertexNum; ++i ){
            Node nodeTemp( i, -1 );
            vNodeVector.push_back( nodeTemp );
        }
        cout<<"Input Edge Relationships:(Head Tail and Weight, Separated by blank)"<<endl;
        for( int i=0; i<nEdgeNum; ++i ){
            int nEdgeHead, nEdgeTail, nInputWeight;
            cin>>nEdgeHead>>nEdgeTail>>nInputWeight;
            Node * pTail = new Node( nEdgeTail, nInputWeight );
            Node * pNode = &vNodeVector[nEdgeHead];
            while( pNode->pNextNode != NULL ){
                pNode = pNode->pNextNode;
            }
            pNode->pNextNode = pTail;
        }
    }
    Graph( int nInputVertex, const map<vector<int>, int> & edgeInfo ):
        nVertexNum( nInputVertex ),
        nEdgeNum( 0 )
    {
        for( int i=0; i<nVertexNum; ++i ){
            Node nodeTemp( i, -1 );
            vNodeVector.push_back( nodeTemp );
        }
        for( auto & i : edgeInfo ){
            int nEdgeHead, nEdgeTail, nInputWeight;
            nEdgeHead = i.first[0];
            nEdgeTail = i.first[1];
            nInputWeight = i.second;
            Node * pTail = new Node( nEdgeTail, nInputWeight );
            Node * pNode = &vNodeVector[nEdgeHead];
            while( pNode->pNextNode != NULL ){
                pNode = pNode->pNextNode;
            }
            pNode->pNextNode = pTail;
        }
    }
    ~Graph(){
        for( auto node : vNodeVector ){
            Node * pNode = node.pNextNode;
            while( pNode != NULL ){
                Node * pNext = pNode->pNextNode;
                delete pNode;
                pNode = pNext;
            }
        }
    }
    void fnPrintGraph(){
        if( vNodeVector.empty() ){
            cout<<"Graph is empty"<<endl;
            return;
        }
        for( auto &node : vNodeVector ){
            cout<<"("<<node.nNodeNo<<")";
            Node * pNode = node.pNextNode;
            while( pNode != NULL ){
                cout<<"->("<<pNode->nNodeNo<<"):"<<pNode->nWeight;
                pNode = pNode->pNextNode;
            }
            cout<<"->NULL"<<endl;
        }
    }
    bool fnBreadthFistSearch( int nSrcNode, int nTerminalNode, vector<int> & vStoTPath ){
        vector<bool> isVisited( nVertexNum, false );
        queue<int> queueNext;
        queueNext.push( nSrcNode );
        isVisited[nSrcNode] = true;
        vector<int> vPath( nVertexNum, -1 );
        for( int & i : vPath ){
            i = -1;
        }
        while( !queueNext.empty() && !isVisited[nTerminalNode] ){
            int nNextNode = queueNext.front();
            queueNext.pop();
            Node * pNode = vNodeVector[nNextNode].pNextNode;
            while( pNode != NULL ){
                if( !isVisited[pNode->nNodeNo] && (pNode->nWeight>0) ) {
                    queueNext.push( pNode->nNodeNo );
                    isVisited[pNode->nNodeNo] = true;
                    vPath[pNode->nNodeNo] = nNextNode;
                }
                pNode = pNode->pNextNode;
            }
        }
        if( isVisited[nTerminalNode] ){
            stack<int> stackPath;
            int nCurNode = nTerminalNode;
            while( vPath[nCurNode] != -1 ){
                stackPath.push( nCurNode );
                nCurNode = vPath[nCurNode];
            }
            stackPath.push( nCurNode );
            while( !stackPath.empty() ){
                vStoTPath.push_back( stackPath.top() );
                stackPath.pop();
            }
        }
        #ifdef DEBUG1
        cout<<"\nPrint Path"<<endl;
        for( int i=0; i<nVertexNum; ++i ){
            int nCurNode = i;
            while( vPath[nCurNode] != -1 ){
                cout<<nCurNode<<"<-";
                nCurNode = vPath[nCurNode];
            }
            cout<<nSrcNode<<endl;
        }
        #endif
        return isVisited[nTerminalNode];
    }
    void fnAddEdge( int nHead, int nTail, int nWeight ){
        if( nHead >= nVertexNum || nTail >= nVertexNum )
            return;

        //Check nHead->nTail;
        Node * pNode = &vNodeVector[nHead];
        while( pNode->pNextNode != NULL ){
            //该边已存在
            if( pNode->nNodeNo == nTail ){
                cout<<"Edge("<<nHead<<")->()"<<nTail<<") exsits!"<<endl;
                return;
            }
            pNode = pNode->pNextNode;
        }
        Node * pNewNode = new Node(nTail, nWeight);
        pNode->pNextNode = pNewNode;
        nEdgeNum++;
    }
    //nChangedVal 为正
    void fnUpdateEdge( int nHead, int nTail, int nChangedVal ){
        if( nHead >= nVertexNum || nTail >= nVertexNum )
            return;
        #ifdef DEBUG
        assert(nChangedVal>=0);
        #endif
        //Update nHead->nTail;
        Node * pNode = vNodeVector[nHead].pNextNode;
        while( pNode != NULL ){
            if( pNode->nNodeNo == nTail ){
                pNode->nWeight -= nChangedVal;
                #ifdef DEBUG
                assert( pNode->nWeight>=0 );
                #endif
                break;
            }
            pNode = pNode->pNextNode;
        }
        //Update nTail->nHead;
        pNode = &vNodeVector[nTail];
        while( pNode->pNextNode != NULL ){
            if( pNode->nNodeNo == nHead ){
                pNode->nWeight += nChangedVal;
                break;
            }
            pNode = pNode->pNextNode;
        }
        if( !pNode->pNextNode ){
            Node * pNewNode = new Node( nHead, nChangedVal );
            pNode->pNextNode = pNewNode;
            nEdgeNum++;
        }
        return;

    }

    int fnGetEdgeNum() const{
        return nEdgeNum;
    }
    int fnGetVertexNum() const{
        return nVertexNum;
    }
    int fnGetEdgeWeight( int nHead, int nTail ) const{
        if( nHead >= nVertexNum || nTail >= nVertexNum )
            return INT_MAX;
        Node * pNode = vNodeVector[nHead].pNextNode;
        while( pNode != NULL ){
            if( pNode->nNodeNo == nTail ){
                return pNode->nWeight;
            }
            pNode = pNode->pNextNode;
        }
        return INT_MAX;
    }
};

int Fold_Fulkerson( Graph & residualNetwork, int nSrcNode, int nTerminalNode ){
    int nVertexNum = residualNetwork.fnGetVertexNum();

    int nMaxFlow = 0;
    vector<int> vPath;
    while( residualNetwork.fnBreadthFistSearch(nSrcNode, nTerminalNode, vPath) ){
        int nMinSegFlow = INT_MAX;
        int nPathSize = vPath.size();

        #ifdef DEBUG
        cout<<"Print augmenting path:";
        cout<<"("<<vPath[0]<<")";
        for( int i=1; i<nPathSize; ++i ){
            cout<<"->("<<vPath[i]<<"):"<<residualNetwork.fnGetEdgeWeight(vPath[i-1], vPath[i]);
        }
        cout<<endl;
        #endif

        //计算增广路径最小Weight
        for( int i=0; i<nPathSize-1; ++i ){
            int nWeight = residualNetwork.fnGetEdgeWeight(vPath[i], vPath[i+1]);
            nMinSegFlow = nMinSegFlow < nWeight ? nMinSegFlow : nWeight;
        }

        //更新残余网路Weight
        for( int i=0; i<nPathSize-1; ++i ){
            residualNetwork.fnUpdateEdge(vPath[i], vPath[i+1], nMinSegFlow);
        }
        nMaxFlow += nMinSegFlow;
        vPath.clear();
    }
    return nMaxFlow;
}

void fnFindPrime( long nNum, vector<bool> & bIsPrime ){

    bIsPrime[0] = false;
    bIsPrime[1] = false;

    int nSqrt = sqrt( (double) nNum );
    int nCount = 0;
    for( int i=2; i<=nSqrt; ++i ){
        if( bIsPrime[i] ){
            for( int j=2; i*j<=nNum; ++j ){
                bIsPrime[ j*i ] = false;
            }
        }
    }
    return ;
}

void fnConstructBipartiteGraph
(
 const vector<int> vNumberArr,
 const vector<bool> bIsPrime,
 map<vector<int>, int> & edgeMapTable
 ){
    int nVertexNum = vNumberArr.size() + 2;
    vector<int> vVertexValue(nVertexNum, -1);
    for( int i=1; i<nVertexNum-1; ++i ){
        vVertexValue[i] = vNumberArr[i-1];
    }
    /* map<vector<int>, int> edgeMapTable; */
    for( int i=1; i<nVertexNum-1; ++i ){
        //奇数与s相连,偶数与t相连
        vector<int> vectorEdgePair(2);
        if( vVertexValue[i] & 1 ) {
            vectorEdgePair[0] = 0;
            vectorEdgePair[1] = i;
            edgeMapTable.insert( make_pair(vectorEdgePair, 1) );
        }
        else{
            vectorEdgePair[0] = i;
            vectorEdgePair[1] = nVertexNum-1;
            edgeMapTable.insert( make_pair(vectorEdgePair, 1) );
        }
    }
    for( int i=1; i<nVertexNum-1; ++i ){
        if( vVertexValue[i] & 1 ) {
            for( int j=1; j<nVertexNum-1; ++j ){
                if( !(vVertexValue[j] & 1) ){
                    if( bIsPrime[vVertexValue[i]+vVertexValue[j]] ){
                        vector<int> vectorEdgePair{ i, j };
                        edgeMapTable.insert( make_pair( vectorEdgePair, 1 ) );
                    }
                }
            }
        }
    }

    #ifdef DEBUG
    for( auto i : edgeMapTable ){
        cout<<vVertexValue[i.first[0]]<<"->"<<vVertexValue[i.first[1]]<<endl;
    }
    #endif
}

int main(int argc, char *argv[])
{
    int nNum;
    cin>>nNum;
    int nMax0=0, nMax1=0;
    vector<int> vNumberArr(nNum, 0);
    for( int i=0; i<nNum; ++i ){
        int nInputNumber;
        cin >> nInputNumber;
        vNumberArr[i] = nInputNumber;
        if( nInputNumber>nMax1 ){
            nMax1 = nInputNumber;
            if( nMax1 > nMax0 ){
                int nTemp = nMax0;
                nMax0 = nMax1;
                nMax1 = nTemp;
            }
        }
    }

    int nMaxPrime = nMax0+nMax1;
    vector<bool> bIsPrime( nMaxPrime+1, true );
    fnFindPrime( nMaxPrime+1, bIsPrime );

    map<vector<int>, int> edgeMapTable;
    fnConstructBipartiteGraph(vNumberArr, bIsPrime, edgeMapTable);
    Graph bipartitGraph( vNumberArr.size()+2, edgeMapTable );
    cout<<Fold_Fulkerson( bipartitGraph, 0, vNumberArr.size()+1 )<<endl;

    /* Graph test; */
    /* test.fnPrintGraph(); */
    /* cout<<Fold_Fulkerson( test, 0, 5 )<<endl; */
    /* test.fnBreadthFistSearch(1,1); */
    return 0;
}
