#include <stdio.h>
#include <stdlib.h>
#include "AlgoritmoMerge.h"

		struct produto{
				int codigo;
				float valor;
			};
		
			typedef struct produto Produto;
		
			struct merge{
				Produto** vetor;
				int n;
				int contador;
			};
			
			typedef struct merge Merge;
			
			Produto* novoProduto(int codigo, float valor){
							Produto *p = (Produto*) malloc(sizeof(Produto)); 
							if(p != NULL){
							p->codigo = codigo;
							p->valor = valor;
						}
							return p; 
							
						}
						
						
			Merge* create(int n){
			 
			Merge *m = (Merge *)malloc(sizeof(Merge));
				 
			if (m != NULL) {
				m->n = n;
				m->contador = 0;
				m->vetor = (Produto**) malloc(n*sizeof(Produto));
			}
			
			return m;
		}			

			void merge(Merge *v,int inicio, int meio, int final){
			 
			  int i,j,k;
			  int n1 = meio - inicio + 1;
			  int n2 = final - meio;
			  Produto**v1 =(Produto**) malloc((n1 + 1) * sizeof(Produto));  
			  Produto**v2 =(Produto**) malloc((n2 + 1) * sizeof(Produto));  
			 
			  for(i=0; i < n1; i++)
			      v1[i] = v->vetor[inicio + i];
			  for(j=0; j< n2; j++)
			     v2[j] = v->vetor[meio + j + 1];
			 
			 Produto p1;
			  p1.codigo = INT_MAX/2;
	
			 Produto p2;
			 p2.codigo =  INT_MAX/2;
			  v1[n1] = &p1;
			  v2[n2] = &p2;
			  
			  i = j = 0;
			  for(k=inicio; k <= final; k++){
			  	
			 if(v1[i]->codigo <= v2[j]->codigo){
			 v->vetor[k] = v1[i];
			 i++;
			 }else{
			 v->vetor[k] = v2[j];
			 j++;
			 }
			  }
			  free(v1);
			  free(v2);
			 
			}
			void mergeSort(Merge *v,int inicio,int fim){
			
			    if(inicio < fim){
			
			    int m = (inicio + fim)/ 2;
			    mergeSort(v,inicio,m);
			    mergeSort(v,m + 1,fim);
			    merge(v,inicio,m,fim);  
			   
			    }
			 }
			int getArraySize(Merge* m){
			  return m != NULL? m->n : -1;
			}
	
			int add(Merge* v, int codigo, float valor){
				
				Produto *p = novoProduto(codigo, valor);
				
				if(p != NULL && v != NULL && v->contador < v->n){
					v->vetor[v->contador++] = p;
					return 1; 
				}else
					return 0;
				
			}
			
			void imprimir(Merge *v){
				int i;
			 	for(i = 0; i < v->contador; i++){
					printf("Produto [%i] = codigo: %i, valor: %.2f \n", i, v->vetor[i]->codigo,v->vetor[i]->valor);
				}
			 }
