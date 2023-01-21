/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graveyard.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarberi <mbarberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 13:07:31 by mbarberi          #+#    #+#             */
/*   Updated: 2023/01/19 16:44:57 by mbarberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ARG=`ruby -e "puts (0..100).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checker -v $ARG

// ../../../../src/push_swap/a.out

99 81 46 36 55 100 32 49 92 31 78 53 42 51 74 85 80 57 96 89 95 4 30 12 2 35 28 41 14 20 90 82 77 44 43 66 37 98 11 62 47 5 71 69 58 33 45 87 22 68 75 29 23 97 59 86 79 83 94 54 70 91 15 93 56 6 60 64 40 34 67 48 25 27 73 13 1 50 8 72 17 76 61 24 21 9 38 84 10 19 26 65 18 88 39 16 52 63 7 3
int	main(int argc, char **argv)
{

	argc = 3;
	(void)argv;
	char *q[] = {"./push_swap", "10", "-12"};

	t_register	*ra;
	t_register	*rb;
	ra = malloc(sizeof(t_register));
	rb = malloc(sizeof(t_register));
	if (argc <= 2 || !ra || !rb)
		return (0);
	if (check_arguments(argc, q))
		return (write(2, "Error\n", 6));
	else
		setup(ra, rb, argc, q);
	// solve(ra, rb);
	printf("\n\nSTACK A FORWARD\n");
	for (t_node *t = ra->head; t; t = t->next)
		printf("%d ", t->data);
/* 	printf("\n\nSTACK A BACKWARD\n");
	for (t_node *t = ra->tail; t; t = t->prev)
		printf("%d ", t->data); */

	perform_action(ra, rb, SA);

	printf("\n\nSTACK A FORWARD\n");
	for (t_node *t = ra->head; t; t = t->next)
		printf("%d ", t->data);
/* 	printf("\n\nSTACK A BACKWARD\n");
	for (t_node *t = ra->tail; t; t = t->prev)
		printf("%d ", t->data);
	return (0); */
}


/* static void	choose_action(t_register *ra, t_register *rb, int pos)
{
	int	med;

	med = ra->size + (ra->size % 2 == 1) / 2;
	if (pos == 2)
		perform_action(ra, rb, SA);
	else if (pos <= med)
		while (--pos)
			perform_action(ra, rb, RA);
	else if (pos > med)
		while (--pos)
			perform_action(ra, rb, RRA);
}
*/

/* static void merge(t_register *ra, t_register *rb)
{
	int i;
	int top_index;
	t_node *p;

	while (rb->size)
	{
		i = 1;
		p = rb->head;
		top_index = ra->head->index;
		while (p && p->index != top_index - 1)
		{
			i++;
			p = p->next;
		}
		choose_action(ra, rb, i);
		perform_action(ra, rb, PA);
	}
} */
242 156 105 295 1 236 232 345 129 41 181 387 393 342 477 283 169 473 491 469 14 402 29 429 65 353 459 151 48 102 26 346 324 88 200 164 457 454 185 334 312 83 415 106 210 416 146 377 455 419 388 472 294 31 209 356 369 11 7 351 38 21 451 243 196 371 298 414 470 316 284 238 305 192 27 241 24 152 189 306 383 233 278 488 290 372 224 354 296 216 257 361 204 240 115 6 317 191 406 494 187 394 499 492 263 4 441 64 177 198 128 325 68 319 321 183 135 203 435 172 79 366 378 60 318 227 313 52 265 92 163 202 194 124 28 66 458 365 50 279 471 422 418 258 67 44 95 134 337 484 288 399 293 212 80 308 453 199 428 274 182 311 69 173 247 273 430 309 144 3 450 352 237 434 417 489 231 248 468 462 465 425 43 381 250 382 84 131 256 18 141 385 142 303 155 368 391 176 125 168 328 205 409 36 220 19 49 225 338 262 307 427 269 498 25 479 251 119 259 412 109 280 483 170 322 82 234 277 442 165 34 246 71 449 207 188 15 487 40 140 261 211 486 376 426 59 443 184 320 123 463 291 253 433 476 244 213 467 389 380 90 221 400 493 76 110 154 180 444 330 160 148 33 118 447 91 201 78 222 113 55 245 77 446 249 73 315 112 121 439 348 35 286 401 480 255 292 485 281 374 367 437 97 215 360 448 304 431 373 104 100 276 167 10 53 272 228 107 235 331 208 270 147 398 460 62 54 333 392 343 56 139 159 96 340 150 42 408 497 358 99 289 287 266 456 267 219 22 179 490 23 466 149 363 445 410 357 58 197 395 275 171 86 230 195 85 396 260 297 111 117 178 217 271 70 482 103 302 120 32 420 440 138 30 239 190 362 5 407 89 93 500 51 2 218 74 405 143 9 264 301 13 413 344 37 12 432 166 481 349 326 436 495 57 474 375 423 299 137 268 390 300 252 153 145 126 122 323 175 339 72 282 61 452 397 158 359 329 75 347 438 39 355 421 424 332 8 327 87 127 98 229 174 335 16 20 130 114 45 206 411 496 226 193 63 108 403 81 47 314 475 310 461 132 464 186 404 94 46 350 341 17 133 101 161 370 379 214 336 384 478 386 136 364 254 223 116 157 285 162


static void	push_slice(t_register *ra, t_register *rb)
{
	int	lo;
	int	up;

	up = 0;
	while (1)
	{
		lo = up;
		up += pick_slice_size(ra, rb);
		while (rb->size != up || ra->size > 3)
		{
			printf("up = %d, lo = %d, rb->size = %d, ra->size = %d\n", up, lo, rb->size, ra->size);
			while (ra->head->index > up)
				perform_action(ra, rb, RA);
			perform_action(ra, rb, PB);
			printf("up = %d, lo = %d, rb->size = %d, ra->size = %d\n", up, lo, rb->size, ra->size);
			if (rb->head && (rb->head->index < ((lo + up) / 2)))
				perform_action(ra, rb, RB);
/* 			if (ra->size == 3)
				return ; */
		}
		if (ra->size == 3)
			break ;
	}
}


static void push_slice(t_register *ra, t_register *rb)
{
	int lo;
	int up;

	up = 0;
	while (1)
	{
		lo = up;
		up += pick_slice_size(ra, rb);
		while (rb->size != up)
		{
			while (ra->head->index > up)
			{
				printf("up = %d, lo = %d, rb->size = %d, ra->size = %d\n", up, lo, rb->size, ra->size);
				perform_action(ra, rb, RA);
			}
			perform_action(ra, rb, PB);
			printf("up = %d, lo = %d, rb->size = %d, ra->size = %d\n", up, lo, rb->size, ra->size);
			if (rb->head && (rb->head->index < ((lo + up) / 2)))
				perform_action(ra, rb, RB);
			if (ra->size <= 3)
				return;
		}
		if (ra->size == 4 || ra->size == 5)
			perform_action(ra, rb, PB);
	}
}
