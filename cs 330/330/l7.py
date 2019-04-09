import re


def mt(name):
    '''Finds the Metaphone value for a word.  Note that only the letters A-Z are
       supported, so any language-specific processing should be done beforehand.
       BAsed on algorithm described by Lawrence Phillips in Computer Language
       Volume 7, No. 12, December 1990, pp 39-43.
       This version is based on one originally written by
       Paul Battley (version 0.4, 2005-04-18, Alpha). pbattley@gmail.com
       Adapted for Python by Deepak Kumar, 2/11/2008. dkumar@cs.brynmawr.edu
    '''
    RULES = [ 
        # Regexp, replacement
        [ r'([bcdfhjklmnpqrstvwxyz])\1+',r'\1' ],# Remove doubled consonants except g.
        [ '^ae',            'E' ], # ae -> E
        [ '^[gkp]n',        'N' ], # initial kn-, gn-, pn- -> N
        [ '^wr',            'R' ], # initial wr- -> R
        [ '^x',             'S' ], # x- -> S
        [ '^wh',            'W' ], # initial wh- -> W
        [ 'mb$',            'M' ], # -mb (as in dumb) -> M
        [ '(?!^)sch',      'SK' ], # sch -> SK
        [ 'th',             '0' ], # 0 represents the th sound
        [ 't?ch|sh',        'X' ], # tch, tsh, ch, sh -> X
        [ 'c(?=ia)',        'X' ], # cia -> X
        [ '[st](?=i[ao])',  'X' ], # stia, stio -> X
        [ 's?c(?=[iey])',   'S' ], # ci, ce, cy, sci, sce, scy -> S
        [ '[cq]',           'K' ], # c, q -> K
        [ 'dg(?=[iey])',    'J' ], # dgi, dge, dgy -> J (as in ledger, edgy)
        [ 'd',              'T' ], # d -> T
        [ 'g(?=h[^aeiou])', ''  ], # gh -> silent (gh- not at end or before vowel)
        [ 'gn(ed)?',        'N' ], # gne, gnd -> N
        [ '([^g]|^)g(?=[iey])',r'\1J' ], # gi, ge, gy, but not gg -> J
        [ 'g+',             'K' ], # g, gg -> K (as in egg)
        [ 'ph',             'F' ], # ph -> F
        [ r'([aeiou])h(?=\b|[^aeiou])',r'\1' ], # silent h if after vowel and no following vowels
        [ '[wy](?![aeiou])', '' ], # wy is silent if not followed by vowel
        [ 'z',              'S' ], # z -> S
        [ 'v',              'F' ], # v -> F
        [ '(?!^)[aeiou]+',  ''  ], # vowels silent unless first letter
    ]

   
    # Normalise case and remove non-ASCII
    name = name.lower()
    s = re.sub('[^a-z]', '', name)
    # Apply the Metaphone rules
    for (rx, rep) in RULES:
        s = re.sub(rx, rep, s)
    return s.upper()


def soundexNaive(name, len=4):
    '''A naive implementation of the soundex algorithm.
       By Deepak Kumar, 2/12/2008. dkumar@brynmawr.edu
       Expects name to be in uppercase.
    '''
    sndx = name[0]  # Keep first letter
    
    for i in name[1:]:
        if i in "BFPV":
            d = "1"
        elif i in "CGJKQSXZ":
            d = "2"
        elif i in "DT":
            d = "3"
        elif i == "L":
            d = "4"
        elif i in "MN":
            d = "5"
        elif i == "R":
            d = "6"
        else:
            d = ''

        # Do not add if repeated/duplicated
        if d != sndx[-1]:
            sndx += d
    return (sndx + (len * '0'))[:len]   # first 4 letters or padd with 0 to make 4



name_dict = {}    
with open('data.txt', 'r')as f:
    lines=f.readlines()
    for line in lines:
        name = line.strip('\n')
        soundex = soundexNaive(name,len=4)
        if soundex in name_dict:
            name_dict[soundex].append(name)
        else:
            name_dict[soundex] = [name]
for key in name_dict.copy():
    if len(name_dict[key]) == 1:
        del name_dict[key]
    
for key in sorted(name_dict, key=lambda key: len(name_dict[key]), reverse=True):
    print(key,name_dict[key])


