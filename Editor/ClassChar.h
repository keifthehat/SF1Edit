				c=wParam;
                switch (focus) {
                case 1://name
                    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9') || c == ' ') {
                        if (strlen(Classes[select[mode]]) < 4) {
                            sprintf(Classes[select[mode]], "%s%c", Classes[select[mode]], c);
                        }
                        else Classes[select[mode]][3] = c;
                    }
                    if (c == 8 && strlen(Classes[select[mode]]) > 0) {
                        Classes[select[mode]][strlen(Classes[select[mode]]) - 1] = 0;
                    }
                    break;
                    //case 2:
                    //case 3:
                    //case 4:
                    //case 5:
                case 6:
                case 7:
                case 8:
                    //case 9:
                    val = c - '0';
                    if (val >= 0 && val < 10) {
                        i = ClassData[select[mode]][focus - 2];
                        if (i < 100) {
                            i *= 10;
                            i += val;
                            ClassData[select[mode]][focus - 2] = i;
                        }
                    }
                    if (c == 8) {
                        i = ClassData[select[mode]][focus - 2];
                        i = i - i % 10;
                        i /= 10;
                        ClassData[select[mode]][focus - 2] = i;
                    }
                    break;
                case 12://spell priority
                    val = c - '0';
                    if (val >= 0 && val < 10) {
                        i = Priority0[select[mode]];
                        if (i < 100) {
                            i *= 10;
                            i += val;
                            Priority0[select[mode]] = i;
                        }
                    }
                    if (c == 8) {
                        i = Priority0[select[mode]];
                        i = i - i % 10;
                        i /= 10;
                        Priority0[select[mode]] = i;
                    }
                    if (Priority0[select[mode]] > 100)Priority0[select[mode]] = 100;
                    break;
                case 50: // Editing BaseResistance
                    val = c - '0';
                    if (val >= 0 && val < 10) {
                        i = BaseResistance;
                        if (i < 256) {
                            i *= 10;
                            i += val;
                            BaseResistance = i;
                        }
                    }
                    if (c == 8) {
                        i = BaseResistance;
                        i = i - i % 10;
                        i /= 10;
                        BaseResistance = i;
                    }
                    break;
                case 51: // Editing 25% Resistance
                    val = c - '0';
                    if (val >= 0 && val < 10) {
                        i = TwentyFiveResistance;
                        if (i < 256) {
                            i *= 10;
                            i += val;
                            TwentyFiveResistance = i;
                        }
                    }
                    if (c == 8) {
                        i = TwentyFiveResistance;
                        i = i - i % 10;
                        i /= 10;
                        TwentyFiveResistance = i;
                    }
                    break;
                case 52: // Editing 50% Resistance
                    val = c - '0';
                    if (val >= 0 && val < 10) {
                        i = FiftyResistance;
                        if (i < 256) {
                            i *= 10;
                            i += val;
                            FiftyResistance = i;
                        }
                    }
                    if (c == 8) {
                        i = FiftyResistance;
                        i = i - i % 10;
                        i /= 10;
                        FiftyResistance = i;
                    }
                    break;
                case 53: // Editing 25% Weakness
                    val = c - '0';
                    if (val >= 0 && val < 10) {
                        i = TwentyFiveWeakness;
                        if (i < 256) {
                            i *= 10;
                            i += val;
                            TwentyFiveWeakness = i;
                        }
                    }
                    if (c == 8) {
                        i = TwentyFiveWeakness;
                        i = i - i % 10;
                        i /= 10;
                        TwentyFiveWeakness = i;
                    }
                    break;
                }