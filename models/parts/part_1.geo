meshPointDist = 0.2;

Point(1) = {1.96137, -2.03863, -5, meshPointDist};
Point(2) = {5, -1.42857, 1.75905e-12, meshPointDist};
Point(3) = {-0.00857264, -1.36292, -2.45247, meshPointDist};
Point(4) = {2.03606, -5, -1.96394, meshPointDist};
Point(5) = {-5, -5, -6.15863e-12, meshPointDist};
Point(6) = {-5, -1.42857, -1.75905e-12, meshPointDist};
Point(7) = {-5, -5, 5, meshPointDist};
Point(8) = {-1.96394, -5, 2.03606, meshPointDist};
Point(9) = {5, -6.15863e-12, -5, meshPointDist};
Point(10) = {5, -5, -5, meshPointDist};
Point(11) = {6.15863e-12, -5, -5, meshPointDist};
Point(12) = {-1.45616, -1.45616, -5, meshPointDist};
Point(13) = {-5, -5, -5, meshPointDist};
Point(14) = {-1.27402, -5, -1.27402, meshPointDist};
Point(15) = {5, -5, 6.15863e-12, meshPointDist};
Point(16) = {-0.765125, -1.64413, 0.886125, meshPointDist};
Point(17) = {1.45433, -5, 1.45433, meshPointDist};
Point(18) = {1.26302, 1.26302, -5, meshPointDist};
Point(19) = {5, 2.21429, -1.5, meshPointDist};
Point(20) = {-5, -6.15863e-12, -5, meshPointDist};
Point(21) = {-5, 2.15714, -1.7, meshPointDist};
Point(22) = {-2.03863, 1.96137, -5, meshPointDist};
Point(23) = {-5, 5, -5, meshPointDist};
Point(24) = {-5, -6.15863e-12, 5, meshPointDist};
Point(25) = {-1.75905e-12, -1.42857, 5, meshPointDist};
Point(26) = {-6.15863e-12, -5, 5, meshPointDist};
Point(27) = {5, -5, 5, meshPointDist};
Point(28) = {-0.164199, 1.60959, -1.76554, meshPointDist};
Line(29) = {6, 21};
Line(30) = {21, 20};
Line(31) = {20, 6};
Line Loop(32) = {29, 30, 31};
Ruled Surface(33) = {32};
Line(34) = {18, 22};
Line(35) = {22, 28};
Line(36) = {28, 18};
Line Loop(37) = {34, 35, 36};
Ruled Surface(38) = {37};
Line(39) = {16, 6};
Line(40) = {6, 24};
Line(41) = {24, 16};
Line Loop(42) = {39, 40, 41};
Ruled Surface(43) = {42};
Line(44) = {4, 10};
Line(45) = {10, 15};
Line(46) = {15, 4};
Line Loop(47) = {44, 45, 46};
Ruled Surface(48) = {47};
Line(49) = {10, 2};
Line(50) = {2, 15};
Line Loop(51) = {49, 50, -45};
Ruled Surface(52) = {51};
Line(53) = {27, 25};
Line(54) = {25, 26};
Line(55) = {26, 27};
Line Loop(56) = {53, 54, 55};
Ruled Surface(57) = {56};
Line(58) = {26, 17};
Line(59) = {17, 27};
Line Loop(60) = {58, 59, -55};
Ruled Surface(61) = {60};
Line(62) = {6, 7};
Line(63) = {7, 24};
Line Loop(64) = {62, 63, -40};
Ruled Surface(65) = {64};
Line(66) = {1, 12};
Line(67) = {12, 18};
Line(68) = {18, 1};
Line Loop(69) = {66, 67, 68};
Ruled Surface(70) = {69};
Line(71) = {2, 9};
Line(72) = {9, 19};
Line(73) = {19, 2};
Line Loop(74) = {71, 72, 73};
Ruled Surface(75) = {74};
Line(76) = {24, 25};
Line(77) = {25, 16};
Line Loop(78) = {-41, 76, 77};
Ruled Surface(79) = {78};
Line(80) = {25, 7};
Line(81) = {7, 26};
Line Loop(82) = {80, 81, -54};
Ruled Surface(83) = {82};
Line(84) = {7, 8};
Line(85) = {8, 26};
Line Loop(86) = {-81, 84, 85};
Ruled Surface(87) = {86};
Line Loop(88) = {-63, -80, -76};
Ruled Surface(89) = {88};
Line(90) = {28, 19};
Line(91) = {19, 18};
Line Loop(92) = {90, 91, -36};
Ruled Surface(93) = {92};
Line(94) = {18, 9};
Line(95) = {9, 1};
Line Loop(96) = {-68, 94, 95};
Ruled Surface(97) = {96};
Line Loop(98) = {-94, -91, -72};
Ruled Surface(99) = {98};
Line(100) = {16, 28};
Line(101) = {28, 6};
Line Loop(102) = {-39, 100, 101};
Ruled Surface(103) = {102};
Line(104) = {5, 14};
Line(105) = {14, 8};
Line(106) = {8, 5};
Line Loop(107) = {104, 105, 106};
Ruled Surface(108) = {107};
Line(109) = {1, 11};
Line(110) = {11, 12};
Line Loop(111) = {109, 110, -66};
Ruled Surface(112) = {111};
Line(113) = {4, 17};
Line(114) = {17, 14};
Line(115) = {14, 4};
Line Loop(116) = {113, 114, 115};
Ruled Surface(117) = {116};
Line(118) = {20, 22};
Line(119) = {22, 12};
Line(120) = {12, 20};
Line Loop(121) = {118, 119, 120};
Ruled Surface(122) = {121};
Line(123) = {9, 10};
Line(124) = {10, 1};
Line Loop(125) = {123, 124, -95};
Ruled Surface(126) = {125};
Line Loop(127) = {-123, -71, -49};
Ruled Surface(128) = {127};
Line(129) = {12, 13};
Line(130) = {13, 20};
Line Loop(131) = {-120, 129, 130};
Ruled Surface(132) = {131};
Line(133) = {10, 11};
Line Loop(134) = {-124, 133, -109};
Ruled Surface(135) = {134};
Line(136) = {4, 11};
Line Loop(137) = {-133, -44, 136};
Ruled Surface(138) = {137};
Line Loop(139) = {-119, -34, -67};
Ruled Surface(140) = {139};
Line(141) = {11, 13};
Line Loop(142) = {141, -129, -110};
Ruled Surface(143) = {142};
Line(144) = {11, 14};
Line(145) = {14, 13};
Line Loop(146) = {-141, 144, 145};
Ruled Surface(147) = {146};
Line(148) = {5, 7};
Line(149) = {6, 5};
Line Loop(150) = {148, -62, 149};
Ruled Surface(151) = {150};
Line Loop(152) = {-148, -106, -84};
Ruled Surface(153) = {152};
Line Loop(154) = {-115, -144, -136};
Ruled Surface(155) = {154};
Line(156) = {15, 17};
Line Loop(157) = {156, -113, -46};
Ruled Surface(158) = {157};
Line(159) = {21, 22};
Line(160) = {22, 23};
Line(161) = {23, 21};
Line Loop(162) = {159, 160, 161};
Ruled Surface(163) = {162};
Line(164) = {20, 23};
Line Loop(165) = {-118, 164, -160};
Ruled Surface(166) = {165};
Line Loop(167) = {-164, -30, -161};
Ruled Surface(168) = {167};
Line(169) = {15, 27};
Line Loop(170) = {-156, 169, -59};
Ruled Surface(171) = {170};
Line(172) = {2, 27};
Line Loop(173) = {-169, -50, 172};
Ruled Surface(174) = {173};
Line(175) = {21, 28};
Line Loop(176) = {-159, 175, -35};
Ruled Surface(177) = {176};
Line Loop(178) = {-175, -29, -101};
Ruled Surface(179) = {178};
Line(180) = {17, 8};
Line Loop(181) = {180, -105, -114};
Ruled Surface(182) = {181};
Line(183) = {2, 16};
Line(184) = {25, 2};
Line Loop(185) = {183, -77, 184};
Ruled Surface(186) = {185};
Line(187) = {2, 28};
Line Loop(188) = {187, -100, -183};
Ruled Surface(189) = {188};
Line(190) = {5, 13};
Line Loop(191) = {-104, 190, -145};
Ruled Surface(192) = {191};
Line(193) = {6, 13};
Line Loop(194) = {-190, -149, 193};
Ruled Surface(195) = {194};
Line Loop(196) = {-85, -180, -58};
Ruled Surface(197) = {196};
Line Loop(198) = {-53, -172, -184};
Ruled Surface(199) = {198};
Line Loop(200) = {-193, -31, -130};
Ruled Surface(201) = {200};
Line Loop(202) = {-73, -90, -187};
Ruled Surface(203) = {202};
Surface Loop(204) = {33, 38, 43, 48, 52, 57, 61, 65, 70, 75, 79, 83, 87, 89, 93, 97, 99, 103, 108, 112, 117, 122, 126, 128, 132, 135, 138, 140, 143, 147, 151, 153, 155, 158, 163, 166, 168, 171, 174, 177, 179, 182, 186, 189, 192, 195, 197, 199, 201, 203};
Volume(205) = {204};