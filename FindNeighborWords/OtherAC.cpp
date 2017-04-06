#include <memory.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
typedef struct dic_words
{
 char word_[50];
// int flag;
}dic_;
void sort_words(dic_  *word_, int length)
{
 int i, j;
 dic_ temp;
 for (i = 0; i < length; i++)
 for (j = i+1; j < length; j++)
 {
  if ( strcmp(word_[i].word_, word_[j].word_) > 0)
  {
   temp = word_[i];
   word_[i] = word_[j];
   word_[j] = temp;
  }
 }
}
int main()
{
 int flag,num;
 int index = 0;
 int i,j,cnts;
 char *p1;
 char *p2;
 dic_*  words = (dic_*)malloc(1000*sizeof(dic_));
 dic_* tempWords = (dic_*)malloc(500*sizeof(dic_));
 char* str = (char *)malloc(200*sizeof(char));
 int* array_ = (int *)malloc(256*sizeof(int));
 memset(str, 0, 200*sizeof(char));
 memset(array_, 0, 256*sizeof(int));
 memset(words, 0, 1000*sizeof(dic_));
 memset(tempWords, 0, 500*sizeof(dic_));
 scanf("%d", &cnts);
 for (i = 0; i < cnts; i++)
 {
  scanf("%s",words[i].word_);
 }
 scanf("%s",str);
 if (*str == NULL)
  return 0;
 //寻找字典里的兄弟单词，并存储在tempWords[500]中
 for (i = 0; i < cnts; i++)
 {
  flag = 0;
  memset(array_, 0, 256*sizeof(int));
  if (0 == strcmp(str, words[i].word_) || strlen(str) != strlen(words[i].word_))
   continue;
  p1 = str;
  p2 = words[i].word_;
  //判断是否为兄弟单词
  while(*p1 != '\0' && *p2 != '\0')
  {
   array_[(int)*p1]++;
   array_[(int)*p2]--;
   p1++;
   p2++;
  }
  for (j = 0; j < 256; j++)
  {
   if (array_[j] != 0)
   {
    flag = 1;
    break;
   }
  }
  if (0 == flag)
   tempWords[index++] = words[i];
 }
 //兄弟单词排序
 sort_words(tempWords, index);
 scanf("%d", &num);
 if (num > index)
  return 0;
 printf("%d\n", index);
 printf("%s", tempWords[num-1].word_);
 free(words);
 free(tempWords);
 free(str);
 free(array_);
 return 0;
}
