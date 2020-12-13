/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
x=0
print(readline().split('')
								.map(x=>x.charCodeAt()-'a'.charCodeAt())
								.reduce((s,a)=>{
									b=s+Math.min(
										Math.abs(a-x),
										26+(a<x?a-x:x-a)
									)
									x=a
									return b
								 },0))