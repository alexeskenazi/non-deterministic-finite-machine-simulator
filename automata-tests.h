#pragma once
#include <string>

using namespace std;

void testBasicStateParsing();
void test(string input_file, string input_string, string expected_output);
void runTests();


const string test1 = R"(
state	1	start
state	2	accept
state	3	startaccept
state	4	acceptstart
)";

const string sample1 = R"(
state	1	start
state	7	accept
transition	1	0	1
transition	1	1	1
transition	1	0	2
transition	2	0	2
transition	2	0	1
transition	2	1	1
transition	2	0	7
transition	7	0	7
transition	7	1	7
)";

const string sample2 = R"(
state	1	start
state	4	accept
state	5	accept
state	6	accept
transition	1	0	1
transition	1	1	2
transition	2	0	2
transition	2	1	3
transition	3	0	3
transition	3	1	4
transition	4	0	4
transition	4	1	4
transition	4	1	5
transition	4	0	5
transition	5	0	5
transition	5	1	5
transition	5	0	6
transition	5	1	6
transition	6	0	6
transition	6	1	6
)";

const string test3 = R"(
state 0 start
state 3 accept
state 4 accept
transition 0 a 1
transition 0 a 2
transition 1 b 3
transition 2 b 4
transition 3 a 3
transition 4 a 4
)";

const string trivial = R"(
state 0 start
state 1 accept
)";

const string homework3a = R"(
state	1	startaccept
state	6	start accept
transition	1	0	1
transition	1	1	2
transition	2	0	3
transition	2	1	2
transition	3	0	1
transition	3	1	4
transition	4	0	5
transition	4	1	2
transition	5	0	1
transition	5	1	6
transition	6	0	6
transition	6	1	6
)";

const string homework3b = R"(
state	1	start
state	2	accept
state	3	accept
state   4   accept
state	6	accept
state	8	accept
transition	1	0	2
transition	1	1	4
transition	2	0	2
transition	2	1	2
transition	4	0	6
transition	4	1	5
transition	5	0	5
transition	5	1	5
transition	6	1	7
transition	7	0	5
transition	7	1	5
)";

const string homework4 = R"(
state 1 start
state 8 accept
state 5 accept
transition 1 1 6
transition 1 0 2
transition 2 0 3
transition 2 1 4
transition 3 0 3
transition 3 1 4
transition 4 0 5
transition 4 1 9
transition 5 0 3
transition 5 1 4
transition 6 0 7
transition 6 1 6
transition 7 0 7
transition 7 1 8
transition 8 0 8
transition 8 1 8
transition 9 0 5
transition 9 1 9
)";

const string superlong = R"(
state   0
state	1	start
state	2
state	3
state	4
state	5
state	6
state	7
state	8
state	9
state	10
state	11
state	12
state	13
state	14
state	15
state	16
state	17
state	18
state	19
state	20
state	21
state	22
state	23
state	24
state	25
state	26
state	27
state	28
state	29
state	30
state	31
state	32
state	33
state	34
state	35
state	36
state	37
state	38
state	39
state	40
state	41
state	42
state	43
state	44
state	45
state	46
state	47
state	48
state	49
state	50
state	51
state	52
state	53
state	54
state	55
state	56
state	57
state	58
state	59
state	60
state	61
state	62
state	63
state	64
state	65
state	66
state	67
state	68
state	69
state	70
state	71
state	72
state	73
state	74
state	75
state	76
state	77
state	78
state	79
state	80
state	81
state	82
state	83
state	84
state	85
state	86
state	87
state	88
state	89
state	90
state	91
state	92
state	93
state	94
state	95
state	96
state	97
state	98
state	99
state	100	accept
state	101
state	102
state	103
state	104
state	105
state	106
state	107
state	108
state	109
state	110
state	111
state	112
state	113
state	114
state	115
state	116
state	117
state	118
state	119
state	120
state	121
state	122
state	123
state	124
state	125
state	126
state	127
state	128
state	129
state	130
state	131
state	132
state	133
state	134
state	135
state	136
state	137
state	138
state	139
state	140
state	141
state	142
state	143
state	144
state	145
state	146
state	147
state	148
state	149
state	150
state	151
state	152
state	153
state	154
state	155
state	156
state	157
state	158
state	159
state	160
state	161
state	162
state	163
state	164
state	165
state	166
state	167
state	168
state	169
state	170
state	171
state	172
state	173
state	174
state	175
state	176
state	177
state	178
state	179
state	180
state	181
state	182
state	183
state	184
state	185
state	186
state	187
state	188
state	189
state	190
state	191
state	192
state	193
state	194
state	195
state	196
state	197
state	198
state	199
state	200	accept
state	201
state	202
state	203
state	204
state	205
state	206
state	207
state	208
state	209
state	210
state	211
state	212
state	213
state	214
state	215
state	216
state	217
state	218
state	219
state	220
state	221
state	222
state	223
state	224
state	225
state	226
state	227
state	228
state	229
state	230
state	231
state	232
state	233
state	234
state	235
state	236
state	237
state	238
state	239
state	240
state	241
state	242
state	243
state	244
state	245
state	246
state	247
state	248
state	249
state	250
state	251
state	252
state	253
state	254
state	255
state	256
state	257
state	258
state	259
state	260
state	261
state	262
state	263
state	264
state	265
state	266
state	267
state	268
state	269
state	270
state	271
state	272
state	273
state	274
state	275
state	276
state	277
state	278
state	279
state	280
state	281
state	282
state	283
state	284
state	285
state	286
state	287
state	288
state	289
state	290
state	291
state	292
state	293
state	294
state	295
state	296
state	297
state	298
state	299
state	300	accept
state	301
state	302
state	303
state	304
state	305
state	306
state	307
state	308
state	309
state	310
state	311
state	312
state	313
state	314
state	315
state	316
state	317
state	318
state	319
state	320
state	321
state	322
state	323
state	324
state	325
state	326
state	327
state	328
state	329
state	330
state	331
state	332
state	333
state	334
state	335
state	336
state	337
state	338
state	339
state	340
state	341
state	342
state	343
state	344
state	345
state	346
state	347
state	348
state	349
state	350
state	351
state	352
state	353
state	354
state	355
state	356
state	357
state	358
state	359
state	360
state	361
state	362
state	363
state	364
state	365
state	366
state	367
state	368
state	369
state	370
state	371
state	372
state	373
state	374
state	375
state	376
state	377
state	378
state	379
state	380
state	381
state	382
state	383
state	384
state	385
state	386
state	387
state	388
state	389
state	390
state	391
state	392
state	393
state	394
state	395
state	396
state	397
state	398
state	399
state	400	accept
state	401
state	402
state	403
state	404
state	405
state	406
state	407
state	408
state	409
state	410
state	411
state	412
state	413
state	414
state	415
state	416
state	417
state	418
state	419
state	420
state	421
state	422
state	423
state	424
state	425
state	426
state	427
state	428
state	429
state	430
state	431
state	432
state	433
state	434
state	435
state	436
state	437
state	438
state	439
state	440
state	441
state	442
state	443
state	444
state	445
state	446
state	447
state	448
state	449
state	450
state	451
state	452
state	453
state	454
state	455
state	456
state	457
state	458
state	459
state	460
state	461
state	462
state	463
state	464
state	465
state	466
state	467
state	468
state	469
state	470
state	471
state	472
state	473
state	474
state	475
state	476
state	477
state	478
state	479
state	480
state	481
state	482
state	483
state	484
state	485
state	486
state	487
state	488
state	489
state	490
state	491
state	492
state	493
state	494
state	495
state	496
state	497
state	498
state	499
state	500	accept
state	501
state	502
state	503
state	504
state	505
state	506
state	507
state	508
state	509
state	510
state	511
state	512
state	513
state	514
state	515
state	516
state	517
state	518
state	519
state	520
state	521
state	522
state	523
state	524
state	525
state	526
state	527
state	528
state	529
state	530
state	531
state	532
state	533
state	534
state	535
state	536
state	537
state	538
state	539
state	540
state	541
state	542
state	543
state	544
state	545
state	546
state	547
state	548
state	549
state	550
state	551
state	552
state	553
state	554
state	555
state	556
state	557
state	558
state	559
state	560
state	561
state	562
state	563
state	564
state	565
state	566
state	567
state	568
state	569
state	570
state	571
state	572
state	573
state	574
state	575
state	576
state	577
state	578
state	579
state	580
state	581
state	582
state	583
state	584
state	585
state	586
state	587
state	588
state	589
state	590
state	591
state	592
state	593
state	594
state	595
state	596
state	597
state	598
state	599
state	600	accept
state	601
state	602
state	603
state	604
state	605
state	606
state	607
state	608
state	609
state	610
state	611
state	612
state	613
state	614
state	615
state	616
state	617
state	618
state	619
state	620
state	621
state	622
state	623
state	624
state	625
state	626
state	627
state	628
state	629
state	630
state	631
state	632
state	633
state	634
state	635
state	636
state	637
state	638
state	639
state	640
state	641
state	642
state	643
state	644
state	645
state	646
state	647
state	648
state	649
state	650
state	651
state	652
state	653
state	654
state	655
state	656
state	657
state	658
state	659
state	660
state	661
state	662
state	663
state	664
state	665
state	666
state	667
state	668
state	669
state	670
state	671
state	672
state	673
state	674
state	675
state	676
state	677
state	678
state	679
state	680
state	681
state	682
state	683
state	684
state	685
state	686
state	687
state	688
state	689
state	690
state	691
state	692
state	693
state	694
state	695
state	696
state	697
state	698
state	699
state	700	accept
state	701
state	702
state	703
state	704
state	705
state	706
state	707
state	708
state	709
state	710
state	711
state	712
state	713
state	714
state	715
state	716
state	717
state	718
state	719
state	720
state	721
state	722
state	723
state	724
state	725
state	726
state	727
state	728
state	729
state	730
state	731
state	732
state	733
state	734
state	735
state	736
state	737
state	738
state	739
state	740
state	741
state	742
state	743
state	744
state	745
state	746
state	747
state	748
state	749
state	750
state	751
state	752
state	753
state	754
state	755
state	756
state	757
state	758
state	759
state	760
state	761
state	762
state	763
state	764
state	765
state	766
state	767
state	768
state	769
state	770
state	771
state	772
state	773
state	774
state	775
state	776
state	777
state	778
state	779
state	780
state	781
state	782
state	783
state	784
state	785
state	786
state	787
state	788
state	789
state	790
state	791
state	792
state	793
state	794
state	795
state	796
state	797
state	798
state	799
state	800	accept
state	801
state	802
state	803
state	804
state	805
state	806
state	807
state	808
state	809
state	810
state	811
state	812
state	813
state	814
state	815
state	816
state	817
state	818
state	819
state	820
state	821
state	822
state	823
state	824
state	825
state	826
state	827
state	828
state	829
state	830
state	831
state	832
state	833
state	834
state	835
state	836
state	837
state	838
state	839
state	840
state	841
state	842
state	843
state	844
state	845
state	846
state	847
state	848
state	849
state	850
state	851
state	852
state	853
state	854
state	855
state	856
state	857
state	858
state	859
state	860
state	861
state	862
state	863
state	864
state	865
state	866
state	867
state	868
state	869
state	870
state	871
state	872
state	873
state	874
state	875
state	876
state	877
state	878
state	879
state	880
state	881
state	882
state	883
state	884
state	885
state	886
state	887
state	888
state	889
state	890
state	891
state	892
state	893
state	894
state	895
state	896
state	897
state	898
state	899
state	900	accept
state	901
state	902
state	903
state	904
state	905
state	906
state	907
state	908
state	909
state	910
state	911
state	912
state	913
state	914
state	915
state	916
state	917
state	918
state	919
state	920
state	921
state	922
state	923
state	924
state	925
state	926
state	927
state	928
state	929
state	930
state	931
state	932
state	933
state	934
state	935
state	936
state	937
state	938
state	939
state	940
state	941
state	942
state	943
state	944
state	945
state	946
state	947
state	948
state	949
state	950
state	951
state	952
state	953
state	954
state	955
state	956
state	957
state	958
state	959
state	960
state	961
state	962
state	963
state	964
state	965
state	966
state	967
state	968
state	969
state	970
state	971
state	972
state	973
state	974
state	975
state	976
state	977
state	978
state	979
state	980
state	981
state	982
state	983
state	984
state	985
state	986
state	987
state	988
state	989
state	990
state	991
state	992
state	993
state	994
state	995
state	996
state	997
state	998
state	999
state	1000	accept
state	1001	accept
state	1002	accept
transition	1	1	2
transition	2	1	3
transition	3	1	4
transition	4	1	5
transition	5	1	6
transition	6	1	7
transition	7	1	8
transition	8	1	9
transition	9	1	10
transition	10	1	11
transition	11	1	12
transition	12	1	13
transition	13	1	14
transition	14	1	15
transition	15	1	16
transition	16	1	17
transition	17	1	18
transition	18	1	19
transition	19	1	20
transition	20	1	21
transition	21	1	22
transition	22	1	23
transition	23	1	24
transition	24	1	25
transition	25	1	26
transition	26	1	27
transition	27	1	28
transition	28	1	29
transition	29	1	30
transition	30	1	31
transition	31	1	32
transition	32	1	33
transition	33	1	34
transition	34	1	35
transition	35	1	36
transition	36	1	37
transition	37	1	38
transition	38	1	39
transition	39	1	40
transition	40	1	41
transition	41	1	42
transition	42	1	43
transition	43	1	44
transition	44	1	45
transition	45	1	46
transition	46	1	47
transition	47	1	48
transition	48	1	49
transition	49	1	50
transition	50	1	51
transition	51	1	52
transition	52	1	53
transition	53	1	54
transition	54	1	55
transition	55	1	56
transition	56	1	57
transition	57	1	58
transition	58	1	59
transition	59	1	60
transition	60	1	61
transition	61	1	62
transition	62	1	63
transition	63	1	64
transition	64	1	65
transition	65	1	66
transition	66	1	67
transition	67	1	68
transition	68	1	69
transition	69	1	70
transition	70	1	71
transition	71	1	72
transition	72	1	73
transition	73	1	74
transition	74	1	75
transition	75	1	76
transition	76	1	77
transition	77	1	78
transition	78	1	79
transition	79	1	80
transition	80	1	81
transition	81	1	82
transition	82	1	83
transition	83	1	84
transition	84	1	85
transition	85	1	86
transition	86	1	87
transition	87	1	88
transition	88	1	89
transition	89	1	90
transition	90	1	91
transition	91	1	92
transition	92	1	93
transition	93	1	94
transition	94	1	95
transition	95	1	96
transition	96	1	97
transition	97	1	98
transition	98	1	99
transition	99	1	100
transition	100	1	101
transition	101	1	102
transition	102	1	103
transition	103	1	104
transition	104	1	105
transition	105	1	106
transition	106	1	107
transition	107	1	108
transition	108	1	109
transition	109	1	110
transition	110	1	111
transition	111	1	112
transition	112	1	113
transition	113	1	114
transition	114	1	115
transition	115	1	116
transition	116	1	117
transition	117	1	118
transition	118	1	119
transition	119	1	120
transition	120	1	121
transition	121	1	122
transition	122	1	123
transition	123	1	124
transition	124	1	125
transition	125	1	126
transition	126	1	127
transition	127	1	128
transition	128	1	129
transition	129	1	130
transition	130	1	131
transition	131	1	132
transition	132	1	133
transition	133	1	134
transition	134	1	135
transition	135	1	136
transition	136	1	137
transition	137	1	138
transition	138	1	139
transition	139	1	140
transition	140	1	141
transition	141	1	142
transition	142	1	143
transition	143	1	144
transition	144	1	145
transition	145	1	146
transition	146	1	147
transition	147	1	148
transition	148	1	149
transition	149	1	150
transition	150	1	151
transition	151	1	152
transition	152	1	153
transition	153	1	154
transition	154	1	155
transition	155	1	156
transition	156	1	157
transition	157	1	158
transition	158	1	159
transition	159	1	160
transition	160	1	161
transition	161	1	162
transition	162	1	163
transition	163	1	164
transition	164	1	165
transition	165	1	166
transition	166	1	167
transition	167	1	168
transition	168	1	169
transition	169	1	170
transition	170	1	171
transition	171	1	172
transition	172	1	173
transition	173	1	174
transition	174	1	175
transition	175	1	176
transition	176	1	177
transition	177	1	178
transition	178	1	179
transition	179	1	180
transition	180	1	181
transition	181	1	182
transition	182	1	183
transition	183	1	184
transition	184	1	185
transition	185	1	186
transition	186	1	187
transition	187	1	188
transition	188	1	189
transition	189	1	190
transition	190	1	191
transition	191	1	192
transition	192	1	193
transition	193	1	194
transition	194	1	195
transition	195	1	196
transition	196	1	197
transition	197	1	198
transition	198	1	199
transition	199	1	200
transition	200	1	201
transition	201	1	202
transition	202	1	203
transition	203	1	204
transition	204	1	205
transition	205	1	206
transition	206	1	207
transition	207	1	208
transition	208	1	209
transition	209	1	210
transition	210	1	211
transition	211	1	212
transition	212	1	213
transition	213	1	214
transition	214	1	215
transition	215	1	216
transition	216	1	217
transition	217	1	218
transition	218	1	219
transition	219	1	220
transition	220	1	221
transition	221	1	222
transition	222	1	223
transition	223	1	224
transition	224	1	225
transition	225	1	226
transition	226	1	227
transition	227	1	228
transition	228	1	229
transition	229	1	230
transition	230	1	231
transition	231	1	232
transition	232	1	233
transition	233	1	234
transition	234	1	235
transition	235	1	236
transition	236	1	237
transition	237	1	238
transition	238	1	239
transition	239	1	240
transition	240	1	241
transition	241	1	242
transition	242	1	243
transition	243	1	244
transition	244	1	245
transition	245	1	246
transition	246	1	247
transition	247	1	248
transition	248	1	249
transition	249	1	250
transition	250	1	251
transition	251	1	252
transition	252	1	253
transition	253	1	254
transition	254	1	255
transition	255	1	256
transition	256	1	257
transition	257	1	258
transition	258	1	259
transition	259	1	260
transition	260	1	261
transition	261	1	262
transition	262	1	263
transition	263	1	264
transition	264	1	265
transition	265	1	266
transition	266	1	267
transition	267	1	268
transition	268	1	269
transition	269	1	270
transition	270	1	271
transition	271	1	272
transition	272	1	273
transition	273	1	274
transition	274	1	275
transition	275	1	276
transition	276	1	277
transition	277	1	278
transition	278	1	279
transition	279	1	280
transition	280	1	281
transition	281	1	282
transition	282	1	283
transition	283	1	284
transition	284	1	285
transition	285	1	286
transition	286	1	287
transition	287	1	288
transition	288	1	289
transition	289	1	290
transition	290	1	291
transition	291	1	292
transition	292	1	293
transition	293	1	294
transition	294	1	295
transition	295	1	296
transition	296	1	297
transition	297	1	298
transition	298	1	299
transition	299	1	300
transition	300	1	301
transition	301	1	302
transition	302	1	303
transition	303	1	304
transition	304	1	305
transition	305	1	306
transition	306	1	307
transition	307	1	308
transition	308	1	309
transition	309	1	310
transition	310	1	311
transition	311	1	312
transition	312	1	313
transition	313	1	314
transition	314	1	315
transition	315	1	316
transition	316	1	317
transition	317	1	318
transition	318	1	319
transition	319	1	320
transition	320	1	321
transition	321	1	322
transition	322	1	323
transition	323	1	324
transition	324	1	325
transition	325	1	326
transition	326	1	327
transition	327	1	328
transition	328	1	329
transition	329	1	330
transition	330	1	331
transition	331	1	332
transition	332	1	333
transition	333	1	334
transition	334	1	335
transition	335	1	336
transition	336	1	337
transition	337	1	338
transition	338	1	339
transition	339	1	340
transition	340	1	341
transition	341	1	342
transition	342	1	343
transition	343	1	344
transition	344	1	345
transition	345	1	346
transition	346	1	347
transition	347	1	348
transition	348	1	349
transition	349	1	350
transition	350	1	351
transition	351	1	352
transition	352	1	353
transition	353	1	354
transition	354	1	355
transition	355	1	356
transition	356	1	357
transition	357	1	358
transition	358	1	359
transition	359	1	360
transition	360	1	361
transition	361	1	362
transition	362	1	363
transition	363	1	364
transition	364	1	365
transition	365	1	366
transition	366	1	367
transition	367	1	368
transition	368	1	369
transition	369	1	370
transition	370	1	371
transition	371	1	372
transition	372	1	373
transition	373	1	374
transition	374	1	375
transition	375	1	376
transition	376	1	377
transition	377	1	378
transition	378	1	379
transition	379	1	380
transition	380	1	381
transition	381	1	382
transition	382	1	383
transition	383	1	384
transition	384	1	385
transition	385	1	386
transition	386	1	387
transition	387	1	388
transition	388	1	389
transition	389	1	390
transition	390	1	391
transition	391	1	392
transition	392	1	393
transition	393	1	394
transition	394	1	395
transition	395	1	396
transition	396	1	397
transition	397	1	398
transition	398	1	399
transition	399	1	400
transition	400	1	401
transition	401	1	402
transition	402	1	403
transition	403	1	404
transition	404	1	405
transition	405	1	406
transition	406	1	407
transition	407	1	408
transition	408	1	409
transition	409	1	410
transition	410	1	411
transition	411	1	412
transition	412	1	413
transition	413	1	414
transition	414	1	415
transition	415	1	416
transition	416	1	417
transition	417	1	418
transition	418	1	419
transition	419	1	420
transition	420	1	421
transition	421	1	422
transition	422	1	423
transition	423	1	424
transition	424	1	425
transition	425	1	426
transition	426	1	427
transition	427	1	428
transition	428	1	429
transition	429	1	430
transition	430	1	431
transition	431	1	432
transition	432	1	433
transition	433	1	434
transition	434	1	435
transition	435	1	436
transition	436	1	437
transition	437	1	438
transition	438	1	439
transition	439	1	440
transition	440	1	441
transition	441	1	442
transition	442	1	443
transition	443	1	444
transition	444	1	445
transition	445	1	446
transition	446	1	447
transition	447	1	448
transition	448	1	449
transition	449	1	450
transition	450	1	451
transition	451	1	452
transition	452	1	453
transition	453	1	454
transition	454	1	455
transition	455	1	456
transition	456	1	457
transition	457	1	458
transition	458	1	459
transition	459	1	460
transition	460	1	461
transition	461	1	462
transition	462	1	463
transition	463	1	464
transition	464	1	465
transition	465	1	466
transition	466	1	467
transition	467	1	468
transition	468	1	469
transition	469	1	470
transition	470	1	471
transition	471	1	472
transition	472	1	473
transition	473	1	474
transition	474	1	475
transition	475	1	476
transition	476	1	477
transition	477	1	478
transition	478	1	479
transition	479	1	480
transition	480	1	481
transition	481	1	482
transition	482	1	483
transition	483	1	484
transition	484	1	485
transition	485	1	486
transition	486	1	487
transition	487	1	488
transition	488	1	489
transition	489	1	490
transition	490	1	491
transition	491	1	492
transition	492	1	493
transition	493	1	494
transition	494	1	495
transition	495	1	496
transition	496	1	497
transition	497	1	498
transition	498	1	499
transition	499	1	500
transition	500	1	501
transition	501	1	502
transition	502	1	503
transition	503	1	504
transition	504	1	505
transition	505	1	506
transition	506	1	507
transition	507	1	508
transition	508	1	509
transition	509	1	510
transition	510	1	511
transition	511	1	512
transition	512	1	513
transition	513	1	514
transition	514	1	515
transition	515	1	516
transition	516	1	517
transition	517	1	518
transition	518	1	519
transition	519	1	520
transition	520	1	521
transition	521	1	522
transition	522	1	523
transition	523	1	524
transition	524	1	525
transition	525	1	526
transition	526	1	527
transition	527	1	528
transition	528	1	529
transition	529	1	530
transition	530	1	531
transition	531	1	532
transition	532	1	533
transition	533	1	534
transition	534	1	535
transition	535	1	536
transition	536	1	537
transition	537	1	538
transition	538	1	539
transition	539	1	540
transition	540	1	541
transition	541	1	542
transition	542	1	543
transition	543	1	544
transition	544	1	545
transition	545	1	546
transition	546	1	547
transition	547	1	548
transition	548	1	549
transition	549	1	550
transition	550	1	551
transition	551	1	552
transition	552	1	553
transition	553	1	554
transition	554	1	555
transition	555	1	556
transition	556	1	557
transition	557	1	558
transition	558	1	559
transition	559	1	560
transition	560	1	561
transition	561	1	562
transition	562	1	563
transition	563	1	564
transition	564	1	565
transition	565	1	566
transition	566	1	567
transition	567	1	568
transition	568	1	569
transition	569	1	570
transition	570	1	571
transition	571	1	572
transition	572	1	573
transition	573	1	574
transition	574	1	575
transition	575	1	576
transition	576	1	577
transition	577	1	578
transition	578	1	579
transition	579	1	580
transition	580	1	581
transition	581	1	582
transition	582	1	583
transition	583	1	584
transition	584	1	585
transition	585	1	586
transition	586	1	587
transition	587	1	588
transition	588	1	589
transition	589	1	590
transition	590	1	591
transition	591	1	592
transition	592	1	593
transition	593	1	594
transition	594	1	595
transition	595	1	596
transition	596	1	597
transition	597	1	598
transition	598	1	599
transition	599	1	600
transition	600	1	601
transition	601	1	602
transition	602	1	603
transition	603	1	604
transition	604	1	605
transition	605	1	606
transition	606	1	607
transition	607	1	608
transition	608	1	609
transition	609	1	610
transition	610	1	611
transition	611	1	612
transition	612	1	613
transition	613	1	614
transition	614	1	615
transition	615	1	616
transition	616	1	617
transition	617	1	618
transition	618	1	619
transition	619	1	620
transition	620	1	621
transition	621	1	622
transition	622	1	623
transition	623	1	624
transition	624	1	625
transition	625	1	626
transition	626	1	627
transition	627	1	628
transition	628	1	629
transition	629	1	630
transition	630	1	631
transition	631	1	632
transition	632	1	633
transition	633	1	634
transition	634	1	635
transition	635	1	636
transition	636	1	637
transition	637	1	638
transition	638	1	639
transition	639	1	640
transition	640	1	641
transition	641	1	642
transition	642	1	643
transition	643	1	644
transition	644	1	645
transition	645	1	646
transition	646	1	647
transition	647	1	648
transition	648	1	649
transition	649	1	650
transition	650	1	651
transition	651	1	652
transition	652	1	653
transition	653	1	654
transition	654	1	655
transition	655	1	656
transition	656	1	657
transition	657	1	658
transition	658	1	659
transition	659	1	660
transition	660	1	661
transition	661	1	662
transition	662	1	663
transition	663	1	664
transition	664	1	665
transition	665	1	666
transition	666	1	667
transition	667	1	668
transition	668	1	669
transition	669	1	670
transition	670	1	671
transition	671	1	672
transition	672	1	673
transition	673	1	674
transition	674	1	675
transition	675	1	676
transition	676	1	677
transition	677	1	678
transition	678	1	679
transition	679	1	680
transition	680	1	681
transition	681	1	682
transition	682	1	683
transition	683	1	684
transition	684	1	685
transition	685	1	686
transition	686	1	687
transition	687	1	688
transition	688	1	689
transition	689	1	690
transition	690	1	691
transition	691	1	692
transition	692	1	693
transition	693	1	694
transition	694	1	695
transition	695	1	696
transition	696	1	697
transition	697	1	698
transition	698	1	699
transition	699	1	700
transition	700	1	701
transition	701	1	702
transition	702	1	703
transition	703	1	704
transition	704	1	705
transition	705	1	706
transition	706	1	707
transition	707	1	708
transition	708	1	709
transition	709	1	710
transition	710	1	711
transition	711	1	712
transition	712	1	713
transition	713	1	714
transition	714	1	715
transition	715	1	716
transition	716	1	717
transition	717	1	718
transition	718	1	719
transition	719	1	720
transition	720	1	721
transition	721	1	722
transition	722	1	723
transition	723	1	724
transition	724	1	725
transition	725	1	726
transition	726	1	727
transition	727	1	728
transition	728	1	729
transition	729	1	730
transition	730	1	731
transition	731	1	732
transition	732	1	733
transition	733	1	734
transition	734	1	735
transition	735	1	736
transition	736	1	737
transition	737	1	738
transition	738	1	739
transition	739	1	740
transition	740	1	741
transition	741	1	742
transition	742	1	743
transition	743	1	744
transition	744	1	745
transition	745	1	746
transition	746	1	747
transition	747	1	748
transition	748	1	749
transition	749	1	750
transition	750	1	751
transition	751	1	752
transition	752	1	753
transition	753	1	754
transition	754	1	755
transition	755	1	756
transition	756	1	757
transition	757	1	758
transition	758	1	759
transition	759	1	760
transition	760	1	761
transition	761	1	762
transition	762	1	763
transition	763	1	764
transition	764	1	765
transition	765	1	766
transition	766	1	767
transition	767	1	768
transition	768	1	769
transition	769	1	770
transition	770	1	771
transition	771	1	772
transition	772	1	773
transition	773	1	774
transition	774	1	775
transition	775	1	776
transition	776	1	777
transition	777	1	778
transition	778	1	779
transition	779	1	780
transition	780	1	781
transition	781	1	782
transition	782	1	783
transition	783	1	784
transition	784	1	785
transition	785	1	786
transition	786	1	787
transition	787	1	788
transition	788	1	789
transition	789	1	790
transition	790	1	791
transition	791	1	792
transition	792	1	793
transition	793	1	794
transition	794	1	795
transition	795	1	796
transition	796	1	797
transition	797	1	798
transition	798	1	799
transition	799	1	800
transition	800	1	801
transition	801	1	802
transition	802	1	803
transition	803	1	804
transition	804	1	805
transition	805	1	806
transition	806	1	807
transition	807	1	808
transition	808	1	809
transition	809	1	810
transition	810	1	811
transition	811	1	812
transition	812	1	813
transition	813	1	814
transition	814	1	815
transition	815	1	816
transition	816	1	817
transition	817	1	818
transition	818	1	819
transition	819	1	820
transition	820	1	821
transition	821	1	822
transition	822	1	823
transition	823	1	824
transition	824	1	825
transition	825	1	826
transition	826	1	827
transition	827	1	828
transition	828	1	829
transition	829	1	830
transition	830	1	831
transition	831	1	832
transition	832	1	833
transition	833	1	834
transition	834	1	835
transition	835	1	836
transition	836	1	837
transition	837	1	838
transition	838	1	839
transition	839	1	840
transition	840	1	841
transition	841	1	842
transition	842	1	843
transition	843	1	844
transition	844	1	845
transition	845	1	846
transition	846	1	847
transition	847	1	848
transition	848	1	849
transition	849	1	850
transition	850	1	851
transition	851	1	852
transition	852	1	853
transition	853	1	854
transition	854	1	855
transition	855	1	856
transition	856	1	857
transition	857	1	858
transition	858	1	859
transition	859	1	860
transition	860	1	861
transition	861	1	862
transition	862	1	863
transition	863	1	864
transition	864	1	865
transition	865	1	866
transition	866	1	867
transition	867	1	868
transition	868	1	869
transition	869	1	870
transition	870	1	871
transition	871	1	872
transition	872	1	873
transition	873	1	874
transition	874	1	875
transition	875	1	876
transition	876	1	877
transition	877	1	878
transition	878	1	879
transition	879	1	880
transition	880	1	881
transition	881	1	882
transition	882	1	883
transition	883	1	884
transition	884	1	885
transition	885	1	886
transition	886	1	887
transition	887	1	888
transition	888	1	889
transition	889	1	890
transition	890	1	891
transition	891	1	892
transition	892	1	893
transition	893	1	894
transition	894	1	895
transition	895	1	896
transition	896	1	897
transition	897	1	898
transition	898	1	899
transition	899	1	900
transition	900	1	901
transition	901	1	902
transition	902	1	903
transition	903	1	904
transition	904	1	905
transition	905	1	906
transition	906	1	907
transition	907	1	908
transition	908	1	909
transition	909	1	910
transition	910	1	911
transition	911	1	912
transition	912	1	913
transition	913	1	914
transition	914	1	915
transition	915	1	916
transition	916	1	917
transition	917	1	918
transition	918	1	919
transition	919	1	920
transition	920	1	921
transition	921	1	922
transition	922	1	923
transition	923	1	924
transition	924	1	925
transition	925	1	926
transition	926	1	927
transition	927	1	928
transition	928	1	929
transition	929	1	930
transition	930	1	931
transition	931	1	932
transition	932	1	933
transition	933	1	934
transition	934	1	935
transition	935	1	936
transition	936	1	937
transition	937	1	938
transition	938	1	939
transition	939	1	940
transition	940	1	941
transition	941	1	942
transition	942	1	943
transition	943	1	944
transition	944	1	945
transition	945	1	946
transition	946	1	947
transition	947	1	948
transition	948	1	949
transition	949	1	950
transition	950	1	951
transition	951	1	952
transition	952	1	953
transition	953	1	954
transition	954	1	955
transition	955	1	956
transition	956	1	957
transition	957	1	958
transition	958	1	959
transition	959	1	960
transition	960	1	961
transition	961	1	962
transition	962	1	963
transition	963	1	964
transition	964	1	965
transition	965	1	966
transition	966	1	967
transition	967	1	968
transition	968	1	969
transition	969	1	970
transition	970	1	971
transition	971	1	972
transition	972	1	973
transition	973	1	974
transition	974	1	975
transition	975	1	976
transition	976	1	977
transition	977	1	978
transition	978	1	979
transition	979	1	980
transition	980	1	981
transition	981	1	982
transition	982	1	983
transition	983	1	984
transition	984	1	985
transition	985	1	986
transition	986	1	987
transition	987	1	988
transition	988	1	989
transition	989	1	990
transition	990	1	991
transition	991	1	992
transition	992	1	993
transition	993	1	994
transition	994	1	995
transition	995	1	996
transition	996	1	997
transition	997	1	998
transition	998	1	999
transition	999	1	1000
transition	1000	1	1000
transition	1002	1	1002
)";