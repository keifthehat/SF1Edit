			c=wParam;
            {
                int i, val;
                long l;
                switch (focus)
                {
                case 1: // Poison
                    val = c - '0';
                    if (val >= 0 && val < 10)
                    {
                        i = Poison;
                        if (i <= 10)
                        {
                            i *= 10;
                            i += val;
                            Poison = i;
                        }
                    }
                    if (c == 8)
                    {
                        i = Poison;
                        i = i - i % 10;
                        i /= 10;
                        Poison = i;
                    }
                    if (Poison > 100)
                        Poison = 100;
                    break;
                case 2: // PoisonOffset (hex)
                    val = c - '0';
                    if (c >= 'a' && c <= 'f')
                        val = c - 'a' + 10;
                    if (c >= 'A' && c <= 'F')
                        val = c - 'A' + 10;
                    if (val >= 0 && val < 16)
                    {
                        l = PoisonOffset;
                        if (l < 524288)
                        {
                            l *= 16;
                            l += val;
                            PoisonOffset = l;
                        }
                    }
                    if (c == 8)
                    {
                        l = PoisonOffset;
                        l = l - l % 16;
                        l /= 16;
                        PoisonOffset = l;
                    }
                    break;
                case 3: // DamageBase
                    val = c - '0';
                    if (val >= 0 && val < 10)
                    {
                        i = DamageBase;
                        if (i <= 10)
                        {
                            i *= 10;
                            i += val;
                            DamageBase = i;
                        }
                    }
                    if (c == 8)
                    {
                        i = DamageBase;
                        i = i - i % 10;
                        i /= 10;
                        DamageBase = i;
                    }
                    if (DamageBase > 100)
                        DamageBase = 100;
                    break;
                case 4: // DamageSpread
                    val = c - '0';
                    if (val >= 0 && val < 10)
                    {
                        i = DamageSpread - 1;
                        if (i <= 10)
                        {
                            i *= 10;
                            i += val;
                            DamageSpread = i + 1;
                        }
                    }
                    if (c == 8)
                    {
                        i = DamageSpread - 1;
                        i = i - i % 10;
                        i /= 10;
                        DamageSpread = i + 1;
                    }
                    if (DamageSpread > 101)
                        DamageSpread = 101;
                    if (DamageSpread < 1)
                        DamageSpread = 1;
                    break;
                case 5: // CritMult
                    val = c - '0';
                    if (val >= 0 && val < 10)
                    {
                        i = CritMult;
                        if (i <= 10)
                        {
                            i *= 10;
                            i += val;
                            CritMult = i;
                        }
                    }
                    if (c == 8)
                    {
                        i = CritMult;
                        i = i - i % 10;
                        i /= 10;
                        CritMult = i;
                    }
                    if (CritMult > 100)
                        CritMult = 100;
                    break;
                case 6: // DoubleChance
                    val = c - '0';
                    if (val >= 0 && val < 10)
                    {
                        i = DoubleChance;
                        if (i <= 10)
                        {
                            i *= 10;
                            i += val;
                            DoubleChance = i;
                        }
                    }
                    if (c == 8)
                    {
                        i = DoubleChance;
                        i = i - i % 10;
                        i /= 10;
                        DoubleChance = i;
                    }
                    if (DoubleChance > 100)
                        DoubleChance = 100;
                    break;
                case 7: // MultiFalloff
                    val = c - '0';
                    if (val >= 0 && val < 10)
                    {
                        i = MultiFalloff;
                        if (i <= 10)
                        {
                            i *= 10;
                            i += val;
                            MultiFalloff = i;
                        }
                    }
                    if (c == 8)
                    {
                        i = MultiFalloff;
                        i = i - i % 10;
                        i /= 10;
                        MultiFalloff = i;
                    }
                    if (MultiFalloff > 100)
                        MultiFalloff = 100;
                    break;
                case 8: // BreakChance
                    val = c - '0';
                    if (val >= 0 && val < 10)
                    {
                        i = BreakChance;
                        if (i <= 10)
                        {
                            i *= 10;
                            i += val;
                            BreakChance = i;
                        }
                    }
                    if (c == 8)
                    {
                        i = BreakChance;
                        i = i - i % 10;
                        i /= 10;
                        BreakChance = i;
                    }
                    if (BreakChance > 100)
                        BreakChance = 100;
                    break;
                case 9: // Unpromoted Level Limit
                    val = c - '0';
                    if (val >= 0 && val < 10)
                    {
                        i = UnLevelLimit;
                        if (i <= 12)
                        {
                            i *= 10;
                            i += val;
                            UnLevelLimit = i;
                        }
                    }
                    if (c == 8)
                    {
                        i = UnLevelLimit;
                        i = i - i % 10;
                        i /= 10;
                        UnLevelLimit = i;
                    }
                    if (UnLevelLimit > 127)
                        UnLevelLimit = 127;
                    break;
                case 10: // Promoted Level Limit
                    val = c - '0';
                    if (val >= 0 && val < 10)
                    {
                        i = LevelLimit;
                        if (i <= 12)
                        {
                            i *= 10;
                            i += val;
                            LevelLimit = i;
                        }
                    }
                    if (c == 8)
                    {
                        i = LevelLimit;
                        i = i - i % 10;
                        i /= 10;
                        LevelLimit = i;
                    }
                    if (LevelLimit > 127)
                        LevelLimit = 127;
                    break;
                case 11: // Promotion Level
                    val = c - '0';
                    if (val >= 0 && val < 10)
                    {
                        i = ProLevel;
                        if (i <= 12)
                        {
                            i *= 10;
                            i += val;
                            ProLevel = i;
                        }
                    }
                    if (c == 8)
                    {
                        i = ProLevel;
                        i = i - i % 10;
                        i /= 10;
                        ProLevel = i;
                    }
                    if (ProLevel > 127)
                        ProLevel = 127;
                    break;
                case 12: // Base Promoted Level (for EXP calc)
                    val = c - '0';
                    if (val >= 0 && val < 10)
                    {
                        i = ProLevelAdd;
                        if (i <= 12)
                        {
                            i *= 10;
                            i += val;
                            ProLevelAdd = i;
                        }
                    }
                    if (c == 8)
                    {
                        i = ProLevelAdd;
                        i = i - i % 10;
                        i /= 10;
                        ProLevelAdd = i;
                    }
                    if (ProLevelAdd > 127)
                        ProLevelAdd = 127;
                    break;
                case 13: // HP EXP Percent
                    val = c - '0';
                    if (val >= 0 && val < 10)
                    {
                        i = HPEXPPercent;
                        if (i <= 12)
                        {
                            i *= 10;
                            i += val;
                            HPEXPPercent = i;
                        }
                    }
                    if (c == 8)
                    {
                        i = HPEXPPercent;
                        i = i - i % 10;
                        i /= 10;
                        HPEXPPercent = i;
                    }
                    if (HPEXPPercent > 100)
                        HPEXPPercent = 100;
                    break;
                case 14: // HP EXP Min
                    val = c - '0';
                    if (val >= 0 && val < 10)
                    {
                        i = HPEXPMin;
                        if (i <= 12)
                        {
                            i *= 10;
                            i += val;
                            HPEXPMin = i;
                        }
                    }
                    if (c == 8)
                    {
                        i = HPEXPMin;
                        i = i - i % 10;
                        i /= 10;
                        HPEXPMin = i;
                    }
                    if (HPEXPMin > 100)
                        HPEXPMin = 100;
                    break;
                case 15: // Promote Stat Percent
                    val = c - '0';
                    if (val >= 0 && val < 10)
                    {
                        i = PromotePercent;
                        if (i < 100)
                        {
                            i *= 10;
                            i += val;
                            PromotePercent = i;
                        }
                    }
                    if (c == 8)
                    {
                        i = PromotePercent;
                        i = i - i % 10;
                        i /= 10;
                        PromotePercent = i;
                    }
                    break;
                case 16: { // Detox EXP
                    int temp;
                    val = c - '0';
                    if (val >= 0 && val < 10)
                    {
                        temp = DetoxEXP;
                        if (temp <= 12)
                        {
                            temp *= 10;
                            temp += val;
                            DetoxEXP = temp;
                        }
                    }
                    if (c == 8)
                    {
                        temp = DetoxEXP;
                        temp = temp - temp % 10;
                        temp /= 10;
                        DetoxEXP = temp;
                    }
                    if (DetoxEXP > 100)
                        DetoxEXP = 100;
                    break;
                }
                case 18: { // Sleep Wake Chance
                    int newVal;
                    val = c - '0';
                    if (val >= 0 && val < 10)
                    {
                        newVal = SleepWakeChance * 10 + val;
                        if (newVal <= 100)
                            SleepWakeChance = newVal;
                    }
                    else if (c == 8)
                    {
                        SleepWakeChance /= 10;
                    }
                    break;
                }
                       // ----- New Cases for Items (Mechanics Page 4) -----
                case 26: { // Unsellable Item 1
                    val = c - '0';
                    if (val >= 0 && val < 10)
                    {
                        i = UnsellableItems[0];
                        if (i <= 99)
                        {
                            i *= 10;
                            i += val;
                            UnsellableItems[0] = i;
                        }
                    }
                    if (c == 8)
                    {
                        i = UnsellableItems[0];
                        i = i - i % 10;
                        i /= 10;
                        UnsellableItems[0] = i;
                    }
                    // Clamp: if not ExtendStatItems, max is 63; else 127.
                    if (!ExtendStatItems && UnsellableItems[0] > 63)
                        UnsellableItems[0] = 63;
                    else if (ExtendStatItems && UnsellableItems[0] > 127)
                        UnsellableItems[0] = 127;
                    break;
                }
                case 27: { // Unsellable Item 2
                    val = c - '0';
                    if (val >= 0 && val < 10)
                    {
                        i = UnsellableItems[1];
                        if (i <= 99)
                        {
                            i *= 10;
                            i += val;
                            UnsellableItems[1] = i;
                        }
                    }
                    if (c == 8)
                    {
                        i = UnsellableItems[1];
                        i = i - i % 10;
                        i /= 10;
                        UnsellableItems[1] = i;
                    }
                    if (!ExtendStatItems && UnsellableItems[1] > 63)
                        UnsellableItems[1] = 63;
                    else if (ExtendStatItems && UnsellableItems[1] > 127)
                        UnsellableItems[1] = 127;
                    break;
                }
                case 28: { // Unsellable Item 3
                    val = c - '0';
                    if (val >= 0 && val < 10)
                    {
                        i = UnsellableItems[2];
                        if (i <= 99)
                        {
                            i *= 10;
                            i += val;
                            UnsellableItems[2] = i;
                        }
                    }
                    if (c == 8)
                    {
                        i = UnsellableItems[2];
                        i = i - i % 10;
                        i /= 10;
                        UnsellableItems[2] = i;
                    }
                    if (!ExtendStatItems && UnsellableItems[2] > 63)
                        UnsellableItems[2] = 63;
                    else if (ExtendStatItems && UnsellableItems[2] > 127)
                        UnsellableItems[2] = 127;
                    break;
                }
                case 29: { // Unsellable Item 4
                    val = c - '0';
                    if (val >= 0 && val < 10)
                    {
                        i = UnsellableItems[3];
                        if (i <= 99)
                        {
                            i *= 10;
                            i += val;
                            UnsellableItems[3] = i;
                        }
                    }
                    if (c == 8)
                    {
                        i = UnsellableItems[3];
                        i = i - i % 10;
                        i /= 10;
                        UnsellableItems[3] = i;
                    }
                    if (!ExtendStatItems && UnsellableItems[3] > 63)
                        UnsellableItems[3] = 63;
                    else if (ExtendStatItems && UnsellableItems[3] > 127)
                        UnsellableItems[3] = 127;
                    break;
                }
                case 30: { // Unsellable Item 5
                    val = c - '0';
                    if (val >= 0 && val < 10)
                    {
                        i = UnsellableItems[4];
                        if (i <= 99)
                        {
                            i *= 10;
                            i += val;
                            UnsellableItems[4] = i;
                        }
                    }
                    if (c == 8)
                    {
                        i = UnsellableItems[4];
                        i = i - i % 10;
                        i /= 10;
                        UnsellableItems[4] = i;
                    }
                    if (!ExtendStatItems && UnsellableItems[4] > 63)
                        UnsellableItems[4] = 63;
                    else if (ExtendStatItems && UnsellableItems[4] > 127)
                        UnsellableItems[4] = 127;
                    break;
                }
                case 31: { // Unsellable Item 6
                    val = c - '0';
                    if (val >= 0 && val < 10)
                    {
                        i = UnsellableItems[5];
                        if (i <= 99)
                        {
                            i *= 10;
                            i += val;
                            UnsellableItems[5] = i;
                        }
                    }
                    if (c == 8)
                    {
                        i = UnsellableItems[5];
                        i = i - i % 10;
                        i /= 10;
                        UnsellableItems[5] = i;
                    }
                    if (!ExtendStatItems && UnsellableItems[5] > 63)
                        UnsellableItems[5] = 63;
                    else if (ExtendStatItems && UnsellableItems[5] > 127)
                        UnsellableItems[5] = 127;
                    break;
                }
                case 32: { // WhoIsJogurt (Force Member ID) – valid range 0–29
                    val = c - '0';
                    if (val >= 0 && val < 10)
                    {
                        i = WhoIsJogurt;
                        if (i <= 99)
                        {
                            i *= 10;
                            i += val;
                            WhoIsJogurt = i;
                        }
                    }
                    if (c == 8)
                    {
                        i = WhoIsJogurt;
                        i = i - i % 10;
                        i /= 10;
                        WhoIsJogurt = i;
                    }
                    if (WhoIsJogurt > 29)
                        WhoIsJogurt = 29;
                    break;
                }
                case 33: { // JogurtItem (Item ID) – same limits as Unsellable items
                    val = c - '0';
                    if (val >= 0 && val < 10)
                    {
                        i = JogurtItem;
                        if (i <= 99)
                        {
                            i *= 10;
                            i += val;
                            JogurtItem = i;
                        }
                    }
                    if (c == 8)
                    {
                        i = JogurtItem;
                        i = i - i % 10;
                        i /= 10;
                        JogurtItem = i;
                    }
                    if (!ExtendStatItems && JogurtItem > 63)
                        JogurtItem = 63;
                    else if (ExtendStatItems && JogurtItem > 127)
                        JogurtItem = 127;
                    break;
                }
                default:
                    break;
                }
            }