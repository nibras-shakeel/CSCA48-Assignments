#include<stdio.h>

#define MAX_STR_LEN 1024

int str_len(char *str) {
  int len = 0;
  while (*str != '\0') {
    str++;
    len++;
  }
  return len;
}

void reverse_str(char *str, int start, int end) {
  while (start < end) {
    char temp = str[start];
    str[start] = str[end];
    str[end] = temp;
    start++;
    end--;
  }
}

void wordSwapper(char *dest, char *src)
{
  int src_len = str_len(src);
  int dest_len = 0;
  int word_start = src_len - 1;
  int word_end = src_len - 1;
  for (int i = src_len - 1; i >= 0; i--) {
    if (src[i] == ' ' || i == 0) {
      if (i != 0) word_end = i - 1;
      reverse_str(src, word_start, word_end);
      for (int j = i; j <= word_start; j++) {
        dest[dest_len] = src[j];
        dest_len++;
      }
      dest[dest_len] = ' ';
      dest_len++;
      word_start = i - 1;
    }
  }
  dest[dest_len - 1] = '\0';
}

int main()
{
    char source[MAX_STR_LEN] = "silence .is a looking bird:the turning; edge, of life. e. e. cummings";
    char destination[MAX_STR_LEN] = "I am a destination string and I contain lots of junk 1234517265716572@qsajdkuhasdgsahiehwjauhiuiuhdsj!";
    printf("The original string is: \n%s\n", source);
    wordSwapper(destination, source);
    printf("Destination string after swapping: \n%s\n", destination);    
    return 0;
}
