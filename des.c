#include<stdio.h>
#include<string.h>

void printArr(char* text,int* arr,int size)
{
	int i;
	printf("%s:[",text);
	for(i=0;i<size;i++)
	{
		if(i%8==0)
		{
			printf("\n\t");
			printf("%d,",arr[i]);
		}
	}
	printf("\n]\n");
}

//CONVERTING HEXA TO BINARY
char hexDigits[]="0123456789ABCDEF";
void convert(char* PT,int* temp,int hexSize)
{
	int i;
	for(i=0;i<hexSize;i++)
	{
		int p,q,r,s;
		p=(i*4);
		q=(i*4)+1;
		r=(i*4)+2;
		s=(i*4)+3;
		switch(PT[i])
		{
			case'0'://0000
				temp[p]=0;temp[q]=0;temp[r]=0;temp[s]=0;
				break;
			case'1'://0001
				temp[p]=0;temp[q]=0;temp[r]=0;temp[s]=1;
				break;
			case'2'://0010
				temp[p]=0;temp[q]=0;temp[r]=1;temp[s]=0;
				break;
			case'3'://0011
				temp[p]=0;temp[q]=0;temp[r]=1;temp[s]=1;
				break;
			case'4'://0100
				temp[p]=0;temp[q]=1;temp[r]=0;temp[s]=0;
				break;
			case'5'://0101
				temp[p]=0;temp[q]=1;temp[r]=0;temp[s]=1;
				break;
			case'6'://0110
				temp[p]=0;temp[q]=1;temp[r]=1;temp[s]=0;
				break;
			case'7'://0111
				temp[p]=0;temp[q]=1;temp[r]=1;temp[s]=1;
				break;
			case'8'://1000
				temp[p]=1;temp[q]=0;temp[r]=0;temp[s]=0;
				break;
			case'9'://1001
				temp[p]=1;temp[q]=0;temp[r]=0;temp[s]=1;
				break;
			case'A':
			case'a'://1010
				temp[p]=1;temp[q]=0;temp[r]=1;temp[s]=0;
				break;
			case'B':
			case'b'://1011
				temp[p]=1;temp[q]=0;temp[r]=1;temp[s]=1;
				break;
			case'C':
			case'c'://1100
				temp[p]=1;temp[q]=1;temp[r]=0;temp[s]=0;
				break;
			case'D':
			case'd'://1101
				temp[p]=1;temp[q]=1;temp[r]=0;temp[s]=1;
				break;
			case'E':
			case'e'://1110
				temp[p]=1;temp[q]=1;temp[r]=1;temp[s]=0;
				break;
			case'F':
			case'f'://1111
				temp[p]=1;temp[q]=1;temp[r]=1;temp[s]=1;
				break;
			default:
				printf("\nINVALID HEXADECIMAL DIGIT ...%c",PT[i]);
		}
	}
}
// BINARY TO DECIMAL

void bin_decimal(int* in, char* hexa, int hexaSize) 
{
	int i, j;
	for (i=0; i< hexaSize; i++)
	{
		int hexVal = 0;
		for (j=0; j<4; j++)
		{
			//PERFORMING BIT-WISE LEFT SHIFT
			hexVal+=in[(i* 4)+j]<<(3-j);
		}
		hexa[i]=hexDigits[hexVal]; //STORING OUTPUT IN hex[]
	}
	hexa[hexaSize] = '\0';
}
void PRINT(char* title, int* in, int hexaSize)
{
	char inHexa[hexaSize + 1];
	bin_decimal(in, inHexa, hexaSize); //CONVERTING BINARY TO DECIMAL
	printf("%s:%s\n", title, inHexa);
}

//Initial Permutation (IP) Table
void ini_per(int input[64], int output[64])
{
	int i;
	int ip[] = { 58, 50, 42, 34, 26, 18, 10, 2,
					60, 52, 44, 36, 28, 20, 12, 4,
					62, 54, 46, 38, 30, 22, 14, 6,
					64, 56, 48, 40, 32, 24, 16, 8,
					57, 49, 41, 33, 25, 17, 9, 1,
					59, 51, 43, 35, 27, 19, 11, 3,
					61, 53, 45, 37, 29, 21, 13, 5,
					63, 55, 47, 39, 31, 23, 15, 7};
	for (i=0; i<64; i++)
	{	
		//GENERATING OUTPUT BASED ON IP ARRAY 
		output[i] = input[ip[i] - 1];
	}
}

//Initial Permutation (IP) inverse Table
void ip_inv(int input[64], int output[64])
{
	int i;
	int ip[] = {    40, 8, 48, 16, 56, 24, 64, 32,
					39, 7, 47, 15, 55, 23, 63, 31,
					38, 6, 46, 14, 54, 22, 62, 30,
					37, 5, 45, 13, 53, 21, 61, 29,
					36, 4, 44, 12, 52, 20, 60, 28,
					35, 3, 43, 11, 51, 19, 59, 27,
					34, 2, 42, 10, 50, 18, 58, 26,
					33, 1, 41, 9, 49, 17, 57, 25
			    };
	for(i=0;i<64;i++)
	{
		output[i]=input[ip[i]-1];
	}
}
void split(int*input,int size,int *a,int*b)
{
	int i,s=size/2;
	for(i=0;i<s;i++)
	{
		a[i]=input[i];//LEFT SUB-PART
	}
	for(i=0;i<s;i++)
	{
		b[i]=input[s+i];//RIGHT SUB-PART
	}
}

//MERGE THE SPLITTED TEXT INVERSELY
void merge(int* a,int* b,int size,int* output)
{
	int i;
	for(i=0;i<size;i++)
	{
		output[i]=a[i];//RIGHT TO LEFT
	}
	for(i=0;i<size;i++)
	{
		output[size+i]=b[i];//LEFT TO RIGHT
	}
}

// expansion_permutation function to convert 48 bit input to 32 bits
void expansion_permutation(int input[], int output[]) {
    int expansion_table[] = {
        32,  1,  2,  3,  4,  5,
         4,  5,  6,  7,  8,  9,
         8,  9, 10, 11, 12, 13,
        12, 13, 14, 15, 16, 17,
        16, 17, 18, 19, 20, 21,
        20, 21, 22, 23, 24, 25,
        24, 25, 26, 27, 28, 29,
        28, 29, 30, 31, 32,  1
    };
    int i, input_bit_index;
    for (i = 0; i < 48; i++) {
		// -1 is for 0-based indexing as above table our team created is not using it
        input_bit_index = expansion_table[i] - 1; 
        output[i] = input[input_bit_index];
    }
}

//EXPANDED PLAIN TEXT (BITWISE X-OR)EXPANDED KEY
void xor_operation(int input1[],  int input2[], int output[], int size) {
	int i;
    for (i = 0; i < size; i++) {
        output[i] = input1[i] ^ input2[i];
    }
}

//DECIMAL TO 4-BIT BINARY
void dec_bin(int in,int out[4])
{
	int j=0;
	while(j!=4)
	{
		if(in==0)
		{
			out[j++]=0;
		}
		while(in!=0)
		{
			out[j++]=in%2;
			in/=2;
		}
	}
}

//S-BOX
void S_Box(int in[48], int out[32])
{
 int sbox[8][4][16]=
 {
    {
        // S0
        {14, 4, 13, 1, 2, 15, 11, 8, 3, 10, 6, 12, 5, 9, 0, 7},
        {0, 15, 7, 4, 14, 2, 13, 1, 10, 6, 12, 11, 9, 5, 3, 8},
        {4, 1, 14, 8, 13, 6, 2, 11, 15, 12, 9, 7, 3, 10, 5, 0},
        {15, 12, 8, 2, 4, 9, 1, 7, 5, 11, 3, 14, 10, 0, 6, 13}
    },
    {
        // S1
        {15, 1, 8, 14, 6, 11, 3, 4, 9, 7, 2, 13, 12, 0, 5, 10},
        {3, 13, 4, 7, 15, 2, 8, 14, 12, 0, 1, 10, 6, 9, 11, 5},
        {0, 14, 7, 11, 10, 4, 13, 1, 5, 8, 12, 6, 9, 3, 2, 15},
        {13, 8, 10, 1, 3, 15, 4, 2, 11, 6, 7, 12, 0, 5, 14, 9}
    },
    {
        // S2
        {10, 0, 9, 14, 6, 3, 15, 5, 1, 13, 12, 7, 11, 4, 2, 8},
        {13, 7, 0, 9, 3, 4, 6, 10, 2, 8, 5, 14, 12, 11, 15, 1},
        {13, 6, 4, 9, 8, 15, 3, 0, 11, 1, 2, 12, 5, 10, 14, 7},
        {1, 10, 13, 0, 6, 9, 8, 7, 4, 15, 14, 3, 11, 5, 2, 12}
    },
    {
        // S3
        {7, 13, 14, 3, 0, 6, 9, 10, 1, 2, 8, 5, 11, 12, 4, 15},
        {13, 8, 11, 5, 6, 15, 0, 3, 4, 7, 2, 12, 1, 10, 14, 9},
        {10, 6, 9, 0, 12, 11, 7, 13, 15, 1, 3, 14, 5, 2, 8, 4},
        {3, 15, 0, 6, 10, 1, 13, 8, 9, 4, 5, 11, 12, 7, 2, 14}
    },
    {
        // S4
        {2, 12, 4, 1, 7, 10, 11, 6, 8, 5, 3, 15, 13, 0, 14, 9},
        {14, 11, 2, 12, 4, 7, 13, 1, 5, 0, 15, 10, 3, 9, 8, 6},
        {4, 2, 1, 11, 10, 13, 7, 8, 15, 9, 12, 5, 6, 3, 0, 14},
        {11, 8, 12, 7, 1, 14, 2, 13, 6, 15, 0, 9, 10, 4, 5, 3}
    },
    {
        // S5
        {12, 1, 10, 15, 9, 2, 6, 8, 0, 13, 3, 4, 14, 7, 5, 11},
        {10, 15, 4, 2, 7, 12, 9, 5, 6, 1, 13, 14, 0, 11, 3, 8},
        {9, 14, 15, 5, 2, 8, 12, 3, 7, 0, 4, 10, 1, 13, 11, 6},
        {4, 3, 2, 12, 9, 5, 15, 10, 11, 14, 1, 7, 6, 0, 8, 13}
    },
    {
        // S6
        {4, 11, 2, 14, 15, 0, 8, 13, 3, 12, 9, 7, 5, 10, 6, 1},
        {13, 0, 11, 7, 4, 9, 1, 10, 14, 3, 5, 12, 2, 15, 8, 6},
        {1, 4, 11, 13, 12, 3, 7, 14, 10, 15, 6, 8, 0, 5, 9, 2},
        {6, 11, 13, 8, 1, 4, 10, 7, 9, 5, 0, 15, 14, 2, 3, 12}
    },
    {
        // S7
        {13, 2, 8, 4, 6, 15, 11, 1, 10, 9, 3, 14, 5, 0, 12, 7},
        {1, 15, 13, 8, 10, 3, 7, 4, 12, 5, 6, 11, 0, 14, 9, 2},
        {7, 11, 4, 1, 9, 12, 14, 2, 0, 6, 10, 13, 15, 3, 5, 8},
        {2, 1, 14, 7, 4, 10, 8, 13, 15, 12, 9, 0, 3, 5, 6, 11},
    }
 };
    //s1
    int i,j;
    int start,end;
    int row,col;
    int temp[6];
    int scount;
    int outcount;
    start =0;
    end =5;
    outcount = 0;
    for(scount=0;scount<8;scount++)//0
    {
       // printf("binary section \n");
        for(i=start;i<=end;i++)
        {
            temp[i] = in[i];//101010
          //  printf("%d ",temp[i]);
        }
       // printf("\n");          
        row = temp[0]*2 + temp[5];//2
        col = temp[1]*8 + temp[2]*4 +temp[3]*2 + temp[4];//5
        int ans = sbox[scount][row][col];//6
        int x=3;
        int y;
        int binary[4] = {0,0,0,0};
       // printf("scount : %d ocount: %d row:%d column:%d  start :%d end:%d \n",scount,outcount,row,col,start,end);
        while(ans>0)
        {
            binary[x] = ans%2;//0110
            ans = ans/2;
            x--;
        }

        //printf("outcount = %d",outcount);
        for(y=0;y<=3;y++)//
        {
            out[y+outcount] = binary[y];
            //printf("output[%d] = %d \n",(y+outcount),output[outcount+y]);
        }
       // printf("S-%d(box) :\n",scount);
        for( i=outcount;i<(outcount+4);i++)
        {   
           //printf("%d ",out[i]);
        }
 
        
        //printf("\n");   
        start = start+6;
        end = end+6; 
        outcount =outcount+4;        
    }

   // printf("total output \n");
    for( i=0;i<32;i++)
        {
            //printf("%d ",out[i]);
        }
}

//P_BOX Permutation Function 
void p_box_permutation(int input[], int output[]) {
    int i, input_bit_index;
    int p_box_permutation[] = {
        16,  7, 20, 21,
        29, 12, 28, 17,
        1, 15, 23, 26,
        5, 18, 31, 10,
        2,  8, 24, 14,
        32, 27,  3,  9,
        19, 13, 30,  6,
        22, 11,  4, 25
    };

    for (i = 0; i < 32; i++) {
        input_bit_index = p_box_permutation[i] - 1;
        output[i] = input[input_bit_index];
    }
}

//ROUND FOR ENCRYPTION AND DECRYPTION
void ROUND(int input[64], char keyHex[12], int out[64], int print)
{
	int inputL[32], inputR[32], outR[32];
	split(input, 64, inputL, inputR); //SPLITTING THE PLAIN TEXT
	if(print)
	{
		//printArr("Input Right", inputR, 32);
	}

	int expanded[48];
	expansion_permutation(inputR,expanded); //EXPANSION OF PLAIN TEXT 32->48
	if(print)
	{
		//printArr("Expansion", expanded, 48);
	}
	int key[48];
	convert(keyHex, key, 12); //HEXADECIMAL TO BINARY
	if(print)
	{
		//printArr("Key", key, 48);
	}
	int xored[48];
	xor_operation(expanded, key, xored, 48); //XOR OPERATION ON KEY AND PT
	if(print)
	{
		//printArr("ExOr", xored, 48);
	}
	
	int sboxed[32];
	S_Box(xored, sboxed); //CONVERSION 48->32 BIT
	if(print)
	{
		//printArr("S-Box", sboxed, 48);
	}
	int permuted[32];
	p_box_permutation(sboxed, permuted); //PERMUTATION OF 32 BITS
	if(print)
	{
		//printArr("Permutation", permuted, 32);
	}
	if(print)
	{
		//printArr("Input Left", inputR, 32);
	}
		//XOR OF LEFT PART PT AND COMPUTED RIGHT PART PT
	xor_operation(inputL, permuted, outR, 32);
	if(print)
	{
		//printArr("ExOr", outR, 32);
	}
	//PT FOR NEXT ROUND(PREVIOUS RIGHT AND XORED RIGHT)
	merge(inputR, outR, 32, out);
	if(print)
	{
		//printArr("Merged Output", out, 64);
	}

	//PRINTING THE PT FOR NEXT ROUND
	printf("\t");
	PRINT("ROUND", out, 16);
}

//SWAPPING OF LEFT AND RIGHT PART OF THE TEXT
void swap(int in[64], int out[64])
{
	int inputL[32], inputR[32];
	split(in, 64, inputL, inputR);//SPLIT THE TEXT
	merge(inputR, inputL, 32, out);//MERGE INVERSELY
}

//ENCRYPTION
void encryption(int plain[64], int cipher[64], char keys[16][12])
{
	int ip[64];
	ini_per(plain, ip); //INITIAL PERMUTATION WITH PT AND IP ARRAY
	
	//PRINTING THE OUTPUT OF INITIAL PERMUTATION
		PRINT("Plain IP", ip, 16);
		printf("\n");
	int i, newP[64];

	//ROUND 1
	printf("1.");
	ROUND(ip, keys[0], newP, 1);

	//ROUND 2 TO 16
	for (i=1;i<16;i++)
	{
		printf("%d. ",i+1);
		ROUND(newP, keys[i], newP, 0);
	}

	//SWAPPING LEFT AND RIGHT AT THE END OF ROUND 16
	int swaped[64];
	swap(newP, swaped);
	PRINT("\nPlain SWAP", swaped, 16); //PRINT SWAPPED
	
	//INVERSE IP ON SWAPPED TEXT AT YHE END OF ROUND 16
	ip_inv(swaped, cipher);
	
	//PRINTING THE CIPHER TEXT
	PRINT("Plain Inverse IP (CT)", cipher, 16);
}

// KEYS FOR EACH ROUND
// STATIC KEY
	char keys[16][12] = {
	"A199A1702F88",
	"E04026EAD322",
	"140F421FC9FA",
	"A00B14D46F2E",
	"62E40205DE55",
	"043225FC1AD8",
	"6885441BA4F4",
	"831470D1F27B",
	"40C01BE9CF8D",
	"CC42E03CBE28",
	"2581321A569F",
	"929308B83D76",
	"A60883DF51A5",
	"F904543EFBC7",
	"3B2210826AE9",
	"D1584D756CD3"
};

//DECRYPTION
void decryption(int ciph[64], int rpt[64], char keys[16][12])
{
	int ip[64];
	ini_per(ciph, ip);//INITIAL PERMUTATION
	PRINT("Cipher IP", ip, 16);
	printf("\n");
	int i, newP[64];
	
	//CALLING ROUND FUNCTIONS WITH KEYS IN REVERSE
	printf("1.");
	ROUND(ip, keys[15], newP, 1);
	for (i=14;i >=0;i--)
	{
		printf("%d. ",14-i+2);
		ROUND(newP, keys[i], newP, 0);
	}
	int swaped[64];
	swap(newP, swaped);//FINAL SWAPPING OF TEXT
	PRINT("\nCipher SWAP", swaped, 16);
	ip_inv(swaped, rpt);//INVERSE INTIAL PERMUTATION
	PRINT("Cipher Inverse IP (RPT)", rpt, 16);
}

int main()
{
	char plainHexa[16];
	puts("Enter 16 Hexadecimal Number :");
	gets(plainHexa);
	int plain[64], cipher[64], rpt[64];
	convert(plainHexa, plain, 16); //HEXADECIMAL TO BINARY
	puts("\n\tENCRYPTION");

	//ENCRYPTION CALLED WITH PLAIN,CIPER,KEY
	//CALLING ENCRYPTION WITH PT,CT AND KEY
	encryption(plain, cipher, keys);
	puts("\n\n\tDECRYPTION");

	//DECRYPTION CALLED WITH CIPER,KEYS,RPT
	//CALLING DECRYPTION WITH CT,RPT AND KEY
	decryption(cipher, rpt, keys);
	puts("\n\n\t---EVERYTHING---");
	PRINT("PLAIN", plain, 16);
	PRINT("CIPHER", cipher, 16);
	PRINT("RPT", rpt, 16);
	return 0;
}
