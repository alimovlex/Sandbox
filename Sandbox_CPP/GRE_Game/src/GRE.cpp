/*
    GRE.cpp
    The module represents my words shuffle game from the GRE Magoosh Application.

    Sandbox

    Created by alimovlex.
    Copyright (c) 2020 alimovlex. All rights reserved.
*/
#include <ctime>
#include <cmath>
#include <fstream>
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <exception>
#include <type_traits>
#include <new>
#include <list>
#include <forward_list>
#include <map>
#include <iterator>
#include <deque>
#include <set>
#include <numeric>
#include <iomanip>
#include <cstring>
#include <string>
#include "Tutorial.hpp"

using namespace std;
static vector <string> current;
void common_words(int number)
{
    vector<string> common_first{"Aberration", "Restive", "Iconoclast", "Ambiguous", "Laconic",
                                "Amalgam", "Profligate", "Qualify", "Chastise", "Impertinent",
                                "Extant", "Venerate", "Harangue", "Venality", "Egregious",
                                "Intimate", "Acrimony", "Calumny", "Ambivalent", "Undermine",
                                "Veracious", "Parsimonious", "Auspicious", "Castigate", "Vindicate",
                                "Innocuous", "Demur", "Mercurial", "Wanting", "Involved",
                                "Galvanize", "Betray", "Maintain", "Censure", "Disinterested",
                                "Equivocal", "Amorphous", "Amenable", "Belie", "Gregarious",
                                "Parochial", "Prevaricate", "Enervate", "Commensurate", "Anomalous",
                                "Ingenuous", "Frugal", "Upbraid", "Artful", "Prodigal"};

    vector<string> common_second{"Eschew", "Mitigate", "Prescience", "Perfidy", "Concede",
                                 "Vociferous", "Volubility", "Recondite", "Mawkish", "Frivolous",
                                 "Rustic", "Gainsay", "Obscure", "Incisive", "Reticent",
                                 "Impudent", "Banal", "Apathetic", "Superfluous", "Germane",
                                 "Gossamer", "Predilection", "Querulous", "Aesthete", "Engender",
                                 "Dogmatic", "Fortuitous", "Dictatorial", "Glut", "Didactic",
                                 "Decorous", "Audacious", "Preclude", "Entrenched", "Meticulous",
                                 "Inexorable", "Diffident", "Exacerbate", "Bucolic", "Chortle",
                                 "Deferential", "Gall", "Cryptic", "Culminate", "Platitude",
                                 "Torpor", "Lambast", "Aesthetic", "Conspicuous", "Culpability"};

    vector<string> common_third{"Abstain", "Ameliorate", "Apathy", "Ascetic", "Avaricious",
                                "Belligerent", "Circumvent", "Contrive", "Delineate", "Derivative",
                                "Derive", "Disaffected", "Eclectic", "Elucidate", "Eminent",
                                "Fallacious", "Forlorn", "Frustrate", "Guile", "Guileless",
                                "Haughty", "Heretic", "Immutable", "Incongruous", "Insidious",
                                "Itinerant", "Jingoism", "Jubilant", "Juxtapose", "Languid",
                                "Magnanimous", "Mollify", "Negligible", "Panache", "Precocious",
                                "Quotidian", "Refractory", "Spurious", "Staunch", "Subsume",
                                "Supplant", "Tantamount", "Tenacious", "Travesty", "Treacherous",
                                "Vehemence", "Vilify", "Rudimentary", "Unequivocal", "Denote"};

    vector<string> common_fourth{"Aberrant", "Abstruse", "Acerbic", "Adamant", "Admonitory",
                                 "Apocryphal", "Blatant", "Bumbling", "Burgeon", "Confound",
                                 "Construe", "Contingent", "Copious", "Decorum", "Denigrate",
                                 "Discrete", "Exalt", "Eradicate", "Espouse", "Exacting",
                                 "Pundit", "Exonerate", "Expound", "Forthcoming", "Hackneyed",
                                 "Iconoclastic", "Idiosyncrasy", "Ignoble", "Implacable", "Implausible",
                                 "Incorrigible", "Indifference", "Ingratiate", "Intransigent", "Largess",
                                 "Laudable", "Myopic", "Opaque", "Ostentatious", "Pedantic",
                                 "Pragmatic", "Provincial", "Reconcile", "Soporific", "Temperance",
                                 "Tortuous", "Underscore", "Unscrupulous", "Refute", "Petulant"};

    vector<string> common_fifth{"Accolade", "Admonish", "Antithetical", "Arcane", "Audacity",
                                "Brazen", "Constituent", "Dilettante", "Foment", "Garrulous",
                                "Haphazard", "Hegemony", "Inimical", "Inscrutable", "Insolent",
                                "Intrepid", "Inveterate", "Irrevocable", "Munificent", "Obsequious",
                                "Ostracize", "Pedestrian", "Pernicious", "Poignant", "Precipitous",
                                "Prolific", "Propitious", "Ravenous", "Repudiate", "Rescind",
                                "Resurgent", "Scrupulous", "Sporadic", "Subversive", "Sycophant",
                                "Tempered", "Trite", "Winsome", "Reverent", "Vacillate",
                                "Austere", "Gauche", "Taciturn", "Arbitrary", "Myriad",
                                "Lionize", "Sanction", "Circumscribe", "Prodigious", "Tractable"};

    vector<string> common_sixth{"Arduous", "Askance", "Bolster", "Clumsy", "Contrition",
                                "Craven", "Deleterious", "Duress", "Edifying", "Efficacious",
                                "Elicit", "Flux", "Harried", "Ignominious", "Maladroit",
                                "Maverick", "Mendacity", "Misconstrue", "Mundane", "Nonplussed",
                                "Nuance", "Opulence", "Placate", "Posit", "Rebuke",
                                "Specious", "Stringent", "Sullen", "Transient", "Fastidious",
                                "Furtive", "Anomaly", "Timorous", "Pejorative", "Esoteric",
                                "Imprudent", "Truncate", "Economical", "Dilatory", "Dispassionate",
                                "Disseminate", "Jovial", "Capricious", "Polemic", "Reproach",
                                "Impartial", "Indecorous", "Appease", "Erudite", "Banality"};

        switch (number)
        {
            case 1:
                current = common_first;
                break;
            case 2:
                current = common_second;
                break;
            case 3:
                current = common_third;
                break;
            case 4:
                current = common_fourth;
                break;
            case 5:
                current = common_fifth;
                break;
            case 6:
                current = common_sixth;
                break;
            default:
                cout<<"The choice is incorrect. Terminating the program."<<endl;
                exit(EXIT_FAILURE);
        }
}

void basic_words(int number)
{
    vector<string> basic_first{"Indignant", "Acme", "Embroiled", "Indict", "Slapdash",
                               "Demure", "Inundate", "Screed", "Macabre", "Inflammatory",
                               "Voracious", "Remiss", "Peruse", "Insolvent", "Reprobate",
                               "Dupe", "Pine", "Serendipity", "Affable", "Vindictive",
                               "Telling", "Unnerve", "Profuse", "Bleak", "Summit",
                               "Dog", "Amiable", "Thrifty", "Erratic", "Stipend",
                               "Diabolical", "Candid", "Pinnacle", "Variance", "Tender",
                               "Mesmerize", "Miser", "Underwrite", "Indigenous", "Err",
                               "Retiring", "Hound", "Demean", "Telltale", "Thoroughgoing",
                               "Spendthrift", "Tirade", "Censor", "Affluent", "Zenith"};

    vector<string> basic_second{"Start", "Sanctimonious", "Avarice", "Catalyst", "Unconscionable",
                                "Misanthrope", "Stem", "Aboveboard", "Heyday", "Immaterial",
                                "Scintillating", "Badger", "Chauvinist", "Apex", "Corroborate",
                                "Becoming", "Exhort", "Cardinal", "Errant", "Imponderable",
                                "Bellicose", "Pugnacious", "Junta", "Pittance", "Check",
                                "Desecrate", "Amuck", "Virago", "Melee", "Hodgepodge",
                                "Animosity", "Checkered", "Cogent", "Ferret", "Moment",
                                "Flush", "Replete", "Vicarious", "Powwow", "Contrite",
                                "Beatific", "Preemptive", "Sanguine", "Cadaverous", "Disparate",
                                "Raft", "Wax", "Extenuating", "Fleece", "Paucity"};

    vector<string> basic_third{"Advocate", "Deter", "Thwart", "Boon", "Transitory",
                               "Apprehension", "Renege", "Jocular", "Inclement", "Patronize",
                               "Guffaw", "Avid", "Dearth", "Consummate", "Obdurate",
                               "Moot", "Ornate", "Endemic", "Malady", "Archaic",
                               "Resolve", "Disheartened", "Ascendancy", "Appreciable", "Impermeable",
                               "Fledgling", "Stolid", "Raffish", "Discriminate", "Incessant",
                               "Muted", "Robust", "Respite", "Impede", "Plodding",
                               "Pithy", "Meander", "Morose", "Flounder", "Elusive",
                               "Autonomously", "Quandary", "Fete", "Ingenuity", "Proponent",
                               "Malleable", "Degrade", "Disenfranchise", "Snide", "Entice"};

    vector<string> basic_fourth{"Altruism", "Genial", "Egotist", "Irresolute", "Pristine",
                                "Contemptuous", "Perpetuate", "Jargon", "Spurn", "Precedent",
                                "Impeccable", "Inadvertent", "Cornucopia", "Detrimental", "Fickle",
                                "Unruly", "Lucid", "Smattering", "Perennial", "Elaborate",
                                "Martial", "Illicit", "Glib", "Buck", "Vacuous",
                                "Debase", "Grovel", "Urbane", "Hamstrung", "Benign",
                                "Pertinent", "Sentimental", "Assuage", "Conducive", "Commendable",
                                "Banish", "Genteel", "Surly", "Assail", "Empathetic",
                                "Uncompromising", "Rankle", "Whimsical", "Euphoria", "Tawdry",
                                "Augment", "Facetious", "Tumult", "Credence", "Derisive"};

    vector<string> basic_fifth{"Retract", "Irk", "Presumption", "Foible", "Credulity",
                               "Impending", "Tact", "Discord", "Brusquely", "Placid",
                               "Destitute", "Tarnish", "Complacent", "Tout", "Connive",
                               "Aphoristic", "Embellish", "Leery", "Derogative", "Goad",
                               "Eke", "Rash", "Smug", "Savvy", "Travail",
                               "Collusion", "Quip", "Exemplify", "Elude", "Devolve",
                               "Pastoral", "Enmity", "Candidness", "Obstinate", "Convoluted",
                               "Peevish", "Unseemly", "Serene", "Squander", "Unprecedented",
                               "Impregnable", "Maxim", "Malevolent", "Steadfast", "Ploy",
                               "Diligent", "Exasperate", "Perturb", "Reservation", "Taxing"};

    vector<string> basic_sixth{"Redress", "Docile", "Incense", "Humdrum", "Eccentric",
                               "Fawn", "Coalesce", "Preempt", "Ascribe", "Implicate",
                               "Foolhardy", "Consecrate", "Veneer", "Evenhanded", "Tribulation",
                               "Wanton", "Behoove", "Besmirch", "Conundrum", "Buttress",
                               "Rakish", "Forthright", "Cohesive", "Rile", "Incumbent",
                               "Presumptuous", "Clemency", "Emulate", "Finagle", "Begrudge",
                               "Cavalier", "Lethargic", "Antedate", "Analogous", "Insipid",
                               "Profusion", "Delegate", "Industrious", "Cerebral", "Precarious",
                               "Prevail", "Deride", "Avert", "Uncanny", "Glean",
                               "Melancholy", "Belittle", "Intermittent", "Piquant", "Irascible"};

    vector<string> basic_seventh{"Discreet", "Hamper", "Dilapidated", "Laborious", "Cumbersome",
                                 "Miscreant", "Besiege", "Debunk", "Enumerate", "Abysmal",
                                 "Evasive", "Compound", "Antiquated", "Malodorous", "Complementary",
                                 "Carping", "Morph", "Stymie", "Futile", "Deliberate",
                                 "Qualm", "Vie", "Obliging", "Constraint", "Inkling",
                                 "Paradoxical", "Vanquish", "Convivial", "Excruciating", "Resignation",
                                 "Creditable", "Misogynist", "Colossal", "Balk", "Perquisite",
                                 "Provisional", "Chivalrous", "Decimation", "Champion", "Cosmopolitan",
                                 "Differentiate", "Boorish", "Sordid", "Staid", "Snub",
                                 "Aphorism", "Inarticulate", "Relegate", "Dispatch", "Amply"};

    switch (number)
    {
        case 1:
            current = basic_first;
            break;
        case 2:
            current = basic_second;
            break;
        case 3:
            current = basic_third;
            break;
        case 4:
            current = basic_fourth;
            break;
        case 5:
            current = basic_fifth;
            break;
        case 6:
            current = basic_sixth;
            break;
        case 7:
            current = basic_seventh;
            break;
        default:
            cout<<"The choice is incorrect. Terminating the program."<<endl;
            exit(EXIT_FAILURE);
    }
}

void advanced_words(int number)
{
    vector<string> advanced_first{"Beg", "Conciliate", "Fractious", "Sedulous", "Apogee",
                                  "Jingoist", "Choleric", "Penurious", "Hector", "Attenuate",
                                  "Catholic", "Turpitude", "Prosaic", "Diatribe", "Nadir",
                                  "Vicissitude", "Artless", "Churlish", "Alacrity", "Apostate",
                                  "Cow", "Contentious", "Lascivious", "Indigent", "Zeitgeist",
                                  "Supercilious", "Anathema", "Chary", "Equivocate", "Malfeasance",
                                  "Byzantine", "Pariah", "Kowtow", "Base", "Expansive",
                                  "Imbibe", "Untoward", "Exegesis", "Saturnine", "Insufferable",
                                  "Ponderous", "Perfunctory", "Arrant", "Factious", "Truculent",
                                  "Feckless", "Expunge", "Defray", "Overweening", "Precipitate"};

    vector<string> advanced_second{"Jaundiced", "Phantasmagorical", "Blinkered", "Tendentious", "Sybarite",
                                   "Gerrymander", "Invective", "Apotheosis", "Excoriate", "Malapropism",
                                   "Schadenfreude", "Benighted", "Parvenu", "Sartorial", "Histrionic",
                                   "Remonstrate", "Cupidity", "Sangfroid", "Maudlin", "Sententious",
                                   "Propitiate", "Vituperate", "Peremptory", "Martinet", "Execrate",
                                   "Impecunious", "Juggernaut", "Arch", "Imbroglio", "Hedge",
                                   "Quisling", "Venial", "Fell", "Arriviste", "Mellifluous",
                                   "Bilious", "Jejune", "Mulct", "Protean", "Disabuse",
                                   "Palimpsest", "Curmudgeon", "Pollyannaish", "Quixotic", "Mettlesome",
                                   "Picayune", "Pyrrhic", "Expurgate", "Limpid", "Factitious"};

    vector<string> advanced_third{"Perspicacious", "Litany", "Prolixity", "Solecism", "Semblance",
                                  "Importune", "Probity", "Vitriolic", "Plucky", "Bowdlerize",
                                  "Punctilious", "Quail", "Unforthcoming", "Umbrage", "Enthrall",
                                  "Epiphany", "Mordant", "Portentous", "Maunder", "Duplicity",
                                  "Artlessness", "Lugubrious", "Anodyne", "Enjoin", "Effrontery",
                                  "Raconteur", "Pecuniary", "Redoubtable", "Hagiographic", "Moribund",
                                  "Lampoon", "Cede", "Grandiloquent", "Gaffe", "Charlatan",
                                  "Sinecure", "Temerity", "Insouciance", "Derelict", "Approbatory",
                                  "Recapitulation", "Anemic", "Provident", "Hail", "Impute",
                                  "Flummox", "Prognostication", "Sagacious", "Primacy", "Illustrious"};

    vector<string> advanced_fourth{"Lacerate", "Subterfuge", "Unpropitious", "Stalwart", "Nonchalant",
                                   "Inviolate", "Peripatetic", "Rarefied", "Puissant", "Flippant",
                                   "Encumber", "Incontrovertible", "Hobble", "Patent", "Invidious",
                                   "Machinate", "Imperious", "Obstreperous", "Spartan", "Unviable",
                                   "Ossify", "Hubris", "Equitable", "Denouement", "Firebrand",
                                   "Ribald", "Apposite", "Puerile", "Inure", "Dispensation",
                                   "Dovetail", "Surreptitious", "Irrefutable", "Impetuous", "Presentiment",
                                   "Cosseted", "Decry", "Unflappable", "Magisterial", "Asperity",
                                   "Crestfallen", "Immure", "Crystallize", "Untenable", "Recrimination",
                                   "Celerity", "Tempestuous", "Improvident", "Corollary", "Intimation"};

    vector<string> advanced_fifth{"Browbeat", "Inanity", "Effervescent", "Ersatz", "Apothegm",
                                  "Arrogate", "Atavism", "Vitriol", "Unprepossessing", "Besotted",
                                  "Artifice", "Hoary", "Meteoric", "Reprisal", "Empiricism",
                                  "Gambit", "Anachronism", "Philistine", "Epigram", "Paragon",
                                  "Pith", "Deign", "Disingenuous", "Untrammeled", "Phlegmatic",
                                  "Doleful", "Percipient", "Exemplar", "Solicitude", "Truculence",
                                  "Appurtenant", "Squelch", "Bemoan", "Ineffable", "Inchoate",
                                  "Languish", "Baleful", "Recrudesce", "Objurgate", "Unstinting",
                                  "Debonair", "Antic", "Embryonic", "Nettlesome", "Broadside",
                                  "Rapprochement", "Brook", "Bristle", "Chagrin", "Chimera"};

    vector<string> advanced_sixth{"Panegyric", "Gumption", "Bromide", "Coterminous", "Enormity",
                                  "Pontificate", "Transmute", "Bridle", "Impervious", "Ethereal",
                                  "Inviolable", "Vaunted", "Inequity", "Autocratic", "Tyro",
                                  "Stultify", "Complicit", "Noisome", "Afford", "Elegiac",
                                  "Malingerer", "Abjure", "Pellucid", "Facile", "Impugn",
                                  "Conflate", "Complaisant", "Unimpeachable", "Discursive", "Internecine",
                                  "Callow", "Dolorous", "Desideratum", "Assiduously", "Proscribe",
                                  "Obtuse", "Desiccated", "Appropriate", "Fecund", "Aplomb",
                                  "Conflagration", "Hauteur", "Unassailable", "Mendicant", "Doughty",
                                  "Proselytize", "Solicitous", "Palatable", "Self-effacing", "Turgid"};

    vector<string> advanced_seventh{"Trenchant", "Extrapolate", "Evanescent", "Row", "Exiguity",
                                    "Obtain", "Bastardization", "Concomitant", "Modicum", "Veritable",
                                    "Pillory", "Bereft", "Enamored", "Halcyon", "Capitulate",
                                    "Chauvinism", "Demonstrative", "Officious", "Infelicitous", "Diminutive",
                                    "Hoodwink", "Adjudicate", "Graft", "Dissemble", "Panacea",
                                    "Raillery", "Oblique", "Cataclysm", "Palaver", "Lachrymose",
                                    "Abrogate", "Dissolution", "Countermand", "Loath", "Dissipate",
                                    "Misattribute", "Ineluctable", "Despot", "Surfeit", "Simulacrum",
                                    "Verisimilitude", "Sardonic", "Exorbitant", "Splenetic", "Ebullient",
                                    "Flag", "Promulgate", "Eponym", "Canard", "Estimable"};
    switch (number)
    {
        case 1:
            current = advanced_first;
            break;
        case 2:
            current = advanced_second;
            break;
        case 3:
            current = advanced_third;
            break;
        case 4:
            current = advanced_fourth;
            break;
        case 5:
            current = advanced_fifth;
            break;
        case 6:
            current = advanced_sixth;
            break;
        case 7:
            current = advanced_seventh;
            break;
        default:
            cout<<"The choice is incorrect. Terminating the program."<<endl;
            exit(EXIT_FAILURE);
    }
}

void extra_words(int number)
{
    
    vector<string> extra_first{"Peroration", "Pertinacious", "Pied", "Pleonasm", "Potentate",
                               "Prolix", "Propinquity", "Purlieus", "Pusillanimous", "Putative",
                               "Erstwhile", "Exculpate", "Exiguous", "Extemporaneous", "Extirpate",
                               "Fey", "Foudroyant", "Frowzy", "Hale", "Harridan",
                               "Insuperable", "Legerdemain", "Limn", "Éclat", "Daedalean"};

    vector<string> extra_second{"Aegis", "Appellation", "Blandish", "Bricolage", "Captious",
                                "Cavil", "Cloying", "Coeval", "Coterie", "Cynosure",
                                "Desuetude", "Distaff", "Dysphemism", "Abatement", "Paternalistic",
                                "Contravene", "Cessation", "Sequestered", "Paltry", "Scanty",
                                "Insouciant", "Diurnal", "Dilated", "Alleviate", "Benevolent"};

    vector<string> extra_third{"Nostrum", "Dementia", "Delusion", "Dismissed", "Stern",
                               "Ruminate", "Aver", "Contortion", "Leniency", "Deluge",
                               "Preposterous", "Renowned", "Addled", "Superstitious", "Fleeting",
                               "Akimbo", "Subservient", "Mercenary", "Demarcate", "Dumbfound",
                               "Addlepated", "Emblematic", "Cajole", "Panned", "Sparing",
                               "Blacklist", "Homily", "Shrewd", "Simpatico", "Effusive",
                               "Syncopated", "Stanza", "Depredate", "Autodidact", "Myrmidon",
                               "Defer", "Presage", "Unbeknownst", "Abhorrent", "Deft",
                               "Consanguineous", "Coltish", "Beguile", "Repulse", "Sentries",
                               "Forebear", "Omnipotent", "Discount", "Recant", "Herald"};

    vector<string> extra_fourth{"Attest", "Desolate", "Lapse", "Steward", "Penitent",
                                "Heterodox", "Entitlement", "Somber", "Curt", "Finesse",
                                "Adversary", "Forgo", "Dystopian", "Medley", "Sobriety",
                                "Manacle", "Shun", "Mélange", "Flabbergast", "Wry",
                                "Feasible", "Eloquent", "Foreshadow", "Elated", "Concur",
                                "Hearken", "Fringe", "Forfeit", "Eulogy", "Gawky",
                                "Surmise", "Incendiary", "Trifling", "Impair", "Judicious",
                                "Recluse", "Zeal", "Juncture", "Lull", "Unearth",
                                "Sap", "Predisposed", "Abridge", "Remedial", "Defamatory",
                                "Offset", "Preamble", "Ingrained", "Supplicate"};

    vector<string> extra_fifth{"Penumbra", "Overrun", "Outdone", "Blithe", "Incendiary",
                               "Odious", "Potable", "Cursory", "Verdant", "Depose",
                               "Squalid", "Motley", "Variegated", "Mirth", "Garland",
                               "Pulchritude", "Lisp", "Repel", "Volatile", "Unstrung",
                               "Caned", "Lacunae", "Antediluvian", "Stasis", "Conjure",
                               "Seraph", "Curb", "Effacement", "Candor", "Banter",
                               "Recede", "Prudent", "Parlous", "Semiotics", "Careen",
                               "Trundle", "Tarry", "Vainglorious", "Inconsolable", "Apposed",
                               "Eremitic", "Bleat", "Rectitude", "Stopgap", "Mores",
                               "Amity", "Solace", "Bedizen", "Arcadian"};

    vector<string> extra_sixth{"Notoriety", "Extraterrestrial", "Inconsequential", "Render", "Adhere",
                               "Sentient", "Torrid", "Pervasive", "Aggrandize", "Libertine",
                               "Conversant", "Profound", "Obviate", "Implode", "Rife",
                               "Phony", "Spate", "Entreaty", "Ubiquitous", "Reap",
                               "Makeshift", "Inform", "Levy", "Subside", "Precursor",
                               "Adverse", "Onerous", "Condone", "Stingy", "Trifle",
                               "Stark", "Incipient", "Abdicate", "Secular", "Landmark",
                               "Deference", "Reimburse", "Belabor", "Posthumous", "Mutiny",
                               "Disjointed", "Tacit", "Penchant", "Precept", "Quibble",
                               "Plummet", "Distill", "Wily"};

    switch (number)
    {
        case 1:
            current = extra_first;
            break;
        case 2:
            current = extra_second;
            break;
        case 3:
            current = extra_third;
            break;
        case 4:
            current = extra_fourth;
            break;
        case 5:
            current = extra_fifth;
            break;
        case 6:
            current = extra_sixth;
            break;
        default:
            cout<<"The choice is incorrect. Terminating the program."<<endl;
            exit(EXIT_FAILURE);
    }
}

void optional_words(int number)
{

    vector<string> optional_first{"Militant", "Rend", "Revel", "Rifle", "Rue",
                                  "Servile", "Shirk", "Sidle", "Simper", "Sober",
                                  "Sophomoric", "Stoic", "Strait", "Suffuse", "Tenuous",
                                  "Verbose", "Wean", "Wizened", "Aboriginal", "Abreast",
                                  "Botch", "Console", "Emasculate", "Extol", "Festoon",
                                  "Fetid", "Harp", "Rein", "Tenet", "Underpin",
                                  "Unilateral", "Vernacular", "Vestige", "Volition", "Windfall",
                                  "Luminous", "Per se", "Perjury", "Perplex", "Personable",
                                  "Posterity", "Pretext", "Privation", "Protracted", "Purported",
                                  "Recalcitrant", "Reciprocal", "Rectify"};

    vector<string> optional_second{"Egress", "Euphemism", "Exhume", "Extort", "Fetters",
                                   "Hapless", "Harrowing", "Ilk", "Imbue", "Inept",
                                   "Layman", "Linchpin", "Lavish", "Nefarious", "Obliquity",
                                   "Reverie", "Overture", "Pall", "Parable", "Parry",
                                   "Peddle", "Perforce", "Portend", "Prelate"};

    vector<string> optional_third{"Prepossessing", "Priggish", "Reel", "Requisite", "Luxuriant",
                                  "Parity", "Nebulous", "Mire", "Marginal", "Tangible",
                                  "Minuscule", "Onus", "Mar", "Niche", "Milieu",
                                  "Nemesis", "Resolute", "Revile", "Secede", "Scathe",
                                  "Lucrative", "Slew", "Subvert", "Scourge", "Subdue"};

    vector<string> optional_fourth{"Reprieve", "Shore", "Tenable", "Retrograde", "Risible",
                                   "Sacrosanct", "Sanguinary", "Serpentine", "Skinflint", "Slaver",
                                   "Sleight", "Soluble", "Sundry", "Supine", "Uncouth",
                                   "Venal", "Viscid", "Waffle", "Wheedle", "Immolate",
                                   "Licentious", "Lieutenant", "Masticate", "Mettle", "Miasma"};

    vector<string> optional_fifth{"Mien", "Misappropriation", "Missive", "Nonpareil", "Obeisance",
                                  "Oblation", "Opine", "Outre", "Sate", "Lurid",
                                  "Ouster", "Palliate", "Panoply", "Parlay", "Piecemeal",
                                  "Plumb", "Plutocrat", "Polity", "Proliferate", "Punitive",
                                  "Quorum", "Requite", "Salient", "Prate", "Prestidigitator"};

    vector<string> optional_sixth{"Permutation", "Preternatural", "Precis", "Quarry", "Quiescent",
                                  "Redolent", "Execrable", "Ontology", "Sedition", "Wastrel",
                                  "Seminal", "Stigma", "Stratify", "Waylay", "Winnow",
                                  "Lithe", "Livid", "Maelstrom", "Manifold", "Marshal",
                                  "Minute", "Minutiae", "Misbegotten", "Mogul", "Morass"};

    vector<string> optional_seventh{"Nascent", "Nexus", "Nondescript", "Conscientious", "Welter",
                                   "Echelon", "Effete", "Effigy", "Excise", "Exigency",
                                   "Lax", "Liaison", "Listless", "Scarify", "Sylph",
                                   "Sylvan", "Synod", "Synoptic", "Tenebrous", "Terpsichorean",
                                   "Unctuous", "Vitiate", "Volant", "Votary", "Waggish"};

    vector<string> optional_eigth{"Rapacious", "Pasquinade", "Rejoinder", "Repine", "Retrench",
                                  "Rout", "Rubicund", "Ruck", "Salubrious", "Salvo",
                                  "Sapid", "Sapient", "Lissome", "Loquacious", "Minatory",
                                  "Misnomer", "Modish", "Metier", "Nicety", "Nugatory",
                                  "Obloquy", "Occlude", "Opprobrious", "Oppugn", "Orotund"};

    vector<string> optional_ninth{"Otiose", "Outstrip", "Paean", "Quiddity", "Scurrilous",
                                  "Sinistral", "Skullduggery", "Sobriquet", "Sodality", "Solstice",
                                  "Somnolent", "Sophistry", "Stentorian", "Supererogatory", "Supervene",
                                  "Susurrant", "Passim", "Patois", "Peculate", "Peregrination"};

    switch (number)
    {
        case 1:
            current = optional_first;
            break;
        case 2:
            current = optional_second;
            break;
        case 3:
            current = optional_third;
            break;
        case 4:
            current = optional_fourth;
            break;
        case 5:
            current = optional_fifth;
            break;
        case 6:
            current = optional_sixth;
            break;
        case 7:
            current = optional_seventh;
            break;
        case 8:
            current = optional_eigth;
            break;
        case 9:
            current = optional_ninth;
            break;
        default:
            cout<<"The choice is incorrect. Terminating the program."<<endl;
            exit(EXIT_FAILURE);
    }


}

void gre_vocabulary()
{
    //---------------------------the vocabulary list---------------------------------------------
    vector <string> :: iterator itr;
    string choice;
    int number = 0; //condition = 0;
    chapter:
    cout<<"Which section of the GRE vocabulary would you like to train?"<<endl;
    cin>>choice;
    /*while(!((choice != "common") && (choice != "COMMON") && (choice != "Common") &&
    (choice != "basic") && (choice != "BASIC") && (choice != "Basic") &&
    ((choice != "advanced") && (choice != "ADVANCED") && (choice != "ADVANCED") )))
    {
        cout<<"False answer entered. Please specify the chapter."<<endl;
        cin>>choice;
    }
     */
    //---------------------------the conditions list---------------------------------------------
    if((choice == "common") || (choice == "COMMON") || (choice == "Common"))
    {
        cout<<"Please provide the number of part from 1 to 6 of the vocabulary list:"<<endl;
        cin>>number;
        common_words(number);
        //integers.empty() == true ? cout << "Vector is empty"<<endl : cout <<"Vector isn't empty"<< endl;
    }

    else if((choice == "basic") || (choice == "BASIC") || (choice == "Basic"))
    {
        cout<<"Please provide the number of part from 1 to 7 of the vocabulary list:"<<endl;
        cin>>number;
        basic_words(number);
    }

    else if((choice == "advanced") || (choice == "ADVANCED") || (choice == "Advanced"))
    {
        cout<<"Please provide the number of part from 1 to 7 of the vocabulary list:"<<endl;
        cin>>number;
        advanced_words(number);
    }
    else if((choice == "extra") || (choice == "EXTRA") || (choice == "Extra"))
    {
        cout<<"Please provide the number of part from 1 to 6 of the vocabulary list:"<<endl;
        cin>>number;
        extra_words(number);
    }
    else if((choice == "optional") || (choice == "OPTIONAL") || (choice == "Optional"))
    {
        cout<<"Please provide the number of part from 1 to 9 of the vocabulary list:"<<endl;
        cin>>number;
        optional_words(number);
    }
    else
    {
    cout<<"False answer entered. Please specify the chapter."<<endl;
    goto chapter;
    }
//---------------------------the shuffle section ---------------------------------------------
    int a=1;
        for(;;)
        {
            srand((unsigned) time(NULL));
            random_shuffle(current.begin(), current.end());
            for (itr = current.begin(); itr != current.end(); itr++)
            {
                cout <<"The "<<a<<" word for the turn: "<<endl;
                cout<<*itr << endl;
                a++;
                cin.get();
            }
            goto chapter;

            //CHANGE THIS LINE!!! THE WORST HARDCODED CODE!!!
            //if (a>=50)
              //  break;
        }

}


