// ---- Program Info Start----
//FileName:     MultiThread.cpp
//
//Author:       Fuchen Duan
//
//Email:        slow295185031@gmail.com
//
//CreatedAt:    2017-03-21 19:21:08
// ---- Program Info End  ----

#include <stdio.h>
#include <pthread.h>

pthread_mutex_t g_Mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t g_Cond1 = PTHREAD_COND_INITIALIZER;
pthread_cond_t g_Cond2 = PTHREAD_COND_INITIALIZER;
pthread_cond_t g_Cond3 = PTHREAD_COND_INITIALIZER;
pthread_cond_t g_Cond4 = PTHREAD_COND_INITIALIZER;


char g_Write [1032];
int g_Index = 0;
bool g_Finish = false;

pthread_t thread1;
pthread_t thread2;
pthread_t thread3;
pthread_t thread4;

void fnInit();
void fnRelease();
void * fnThreadFunc1( void * arg );
void * fnThreadFunc2( void * arg );
void * fnThreadFunc3( void * arg );
void * fnThreadFunc4( void * arg );

void fnInit(){

    long nNum;
    scanf( "%ld", &nNum );

    pthread_create( &thread1, NULL, fnThreadFunc1, ( void * ) nNum );
    pthread_create( &thread2, NULL, fnThreadFunc2, ( void * ) nNum );
    pthread_create( &thread3, NULL, fnThreadFunc3, ( void * ) nNum );
    pthread_create( &thread4, NULL, fnThreadFunc4, ( void * ) nNum );

    void * res;
    pthread_join( thread1, &res );

    for( int i=0; i<g_Index; ++i ){
        printf("%c", g_Write[i]);
    }

}

void fnRelease(){
    pthread_cancel( thread1 );
    pthread_cancel( thread2 );
    pthread_cancel( thread3 );
    pthread_cancel( thread4 );
}

void * fnThreadFunc1( void * arg ){
    long nNum = ( long ) arg;

    for( ; nNum > 0 ; ){
        pthread_mutex_lock( &g_Mutex );
        while( g_Index % 4 != 0 )
            pthread_cond_wait( &g_Cond1, &g_Mutex );
        if( g_Index > 1032 ) return NULL;
        g_Write[ g_Index++ ] = 'A';
        nNum --;
        if( nNum == 0 ) g_Finish = true;
        pthread_cond_signal( &g_Cond2 );
        pthread_mutex_unlock( &g_Mutex );
    }
    return NULL;
}

void * fnThreadFunc2( void * arg ){
    for( ; ; ){
        pthread_mutex_lock( &g_Mutex );
        while( g_Index % 4 != 1 ){
            pthread_cond_wait( &g_Cond2, &g_Mutex );
        }
        if( g_Index > 1032 ) return NULL;
        g_Write[ g_Index++ ] = 'B';
        pthread_cond_signal( &g_Cond3 );
        pthread_mutex_unlock( &g_Mutex );
    }
    return NULL;

}

void * fnThreadFunc3( void * arg ){
    for( ; ; ){
        pthread_mutex_lock( &g_Mutex );
        while( g_Index % 4 != 2 ){
            pthread_cond_wait( &g_Cond3, &g_Mutex );
        }
        if( g_Index > 1032 ) return NULL;
        g_Write[ g_Index++ ] = 'C';
        pthread_cond_signal( &g_Cond4 );
        pthread_mutex_unlock( &g_Mutex );
    }
    return NULL;

}

void * fnThreadFunc4( void * arg ){
    for( ; ; ){
        pthread_mutex_lock( &g_Mutex );
        while( g_Index % 4 != 3 ){
            pthread_cond_wait( &g_Cond4, &g_Mutex );
        }
        if( g_Index > 1032 ) return NULL;
        g_Write[ g_Index++ ] = 'D';
        pthread_cond_signal( &g_Cond1 );
        pthread_mutex_unlock( &g_Mutex );
    }
    return NULL;

}

int main(int argc, char *argv[])
{
    fnInit();
    fnRelease();
    return 0;
}
