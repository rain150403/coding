//转自：https://www.cnblogs.com/solidblog/archive/2012/07/30/2616077.html

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WORD_MAX_LENGTH 100
#define DIC_NUM 20000

/*save word before sign*/
char word[DIC_NUM][WORD_MAX_LENGTH];

/*save word after sign*/
char word_sign[DIC_NUM][WORD_MAX_LENGTH];

char old_world_sign[WORD_MAX_LENGTH];

int comp( const void *a, const void *b ){
	return *(char *)a - *(char *)b;
}

int str_compare( const void *a, const void *b ){
	return strcmp( (char *)a, (char *)b );
}

int sign_sort( char* dic ){
	int index = 0;
	int i;
	FILE* fp_dic;
	FILE* fp_tmp;

	fp_dic = fopen( dic, "r" );
	fp_tmp = fopen( "tmp.txt", "w" );
	if( fp_dic == NULL || fp_tmp == NULL ){
		printf( "File operator error !\n" );
		return -1;
	}

	while( fscanf( fp_dic, "%s", word[index] ) != EOF ){
		strcpy(word_sign[index], word[index] );
		/*sign word*/
		qsort( word_sign[index], strlen( word_sign[index] ), sizeof(char), comp );
		strcat( word_sign[index], ": ");
		strcat( word_sign[index], word[index] );
		index++;
	}

	/*sign string*/
	qsort( word_sign, index, sizeof(word_sign[index]), str_compare );
	for( i = 0; i < index; i++ ){
		fprintf( fp_tmp, "%s\n", word_sign[i] );
	}

	fclose( fp_dic );
	fclose( fp_tmp );

	return 0;
}

int squash( char* output ){
	FILE *fp_tmp;
	FILE *fp_output;
	int index = 0;
	int count = 0;

	fp_tmp = fopen( "tmp.txt", "r" );
	fp_output = fopen( output, "w" );

	if( fp_tmp == NULL || fp_output == NULL ){
		printf( "File operation error ！\n" );
		return -1;
	}

	while( fscanf(fp_tmp, "%s %s", word_sign[index], word[index] ) != EOF ){
		if( strcmp( old_world_sign, word_sign[index] ) != 0 && count > 0 ){
			fprintf( fp_output, "\n" );
		}

		strcpy( old_world_sign, word_sign[index] );
		count++;
		fprintf( fp_output, "%s ", word[index++] );
	}

	fclose( fp_output );
	fclose( fp_tmp );

	return 0;
}

int main(){
	char dic[WORD_MAX_LENGTH];
	char output[WORD_MAX_LENGTH];

	printf( "please input dic name : " );
	scanf( "%s", dic );

	printf( "please input output file : " );
	scanf( "%s", output );

	sign_sort( dic );

	squash( output );

	return 0;
}
