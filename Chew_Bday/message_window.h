#ifndef MESSAGE_WINDOW_H
#define MESSAGE_WINDOW_H

#include <QWidget>
#include "mainwindow.h"
#include <QStringList>
#include <QPainter>
#include <QTimer>
#include <QRandomGenerator>
#include <QVector>

namespace Ui {
class message_window;
}

class message_window : public QWidget
{
    Q_OBJECT

public:
    explicit message_window(MainWindow *window, QWidget *parent = nullptr);
    ~message_window();
    QStringList messages = {"Mies: Have you been to just instances yet? Chew: No, it's intimidating",
                            "Im tempted to get more trackers xD",
                            "Ur a good friend mies Honestly",
                            "Just had crazy good erp, need to take a shower after that xD",
                            "Ill get on vrc once im bored of life again :P",
                            "Mies: What heppened with teeny? Chew: Cold feet...",
                            "Wow gj me, couldnt just stfu had to just go and lose a great friend woooo holy fuck im retarded sometimes",
                            "Chew: Im back! Mies: Hi back im dad!",
                            "Getting trauma dumped gives me perspective on what NOT to do with people",
                            "I wouldnt mind if you trauma dump on me mies ur a good friend",
                            "If you call me a slut then Wamdus is like a slut GOD",
                            "If you would have problems it sometimes helps to just have ppl listen, you aint alone buddy",
                            "Thank you for being such a great friend",
                            "Mies: You look fucking good. Chew: Fuckable? (JK)",
                            "When I'm alone I tend to overthink stuff which isn't good. Then I become sad. And drink",
                            "Gonna send ya the saltiest salmiakki known to man (Never sends anything)",
                            "Eat your weird pickles and coffee breakfast..",
                            "Mies: Im fat af. Chew: Bruh no you are not. Mies: Huh? You have eyes right?",
                            "Wamdus got a new boyfriend, dont think its gonna last long tho",
                            "If the kids misbehave tell em ill come beat em up or something idfk",
                            "Chew: Browsed gumroad, Bad idea.. Mies: We gotta ban you from gumroad",
                            "Ur getting the furality ticket you don't have a choice xD",
                            "Mies: You havent taken the 'Mies erp course' Chew: Imma take the next opening",
                            "You do know if you actually wanna erp at somepoint just ask. Ik you wont and thats why i can bully and tease you :3",
                            "You're too much of a good friend to me for me to erp with you though",
                            "About earlier, saying you were late don't mind it I was just giving you shit for no reason",
                            "Damn you horny fuck, but that makes you who you are so..",
                            "I feel the more I hangout with you the more I started becoming a gooner",
                            "Pipeline = more time you spend on this game the more gay/goonery you become",
                            "'Gifts discord nitro' For being a SIMP!!!!",
                            "The EMO CHEWY will RISE!",
                            "Enjoying my misery, you sadist old MAN",
                            "Youre one of the 2 ppl who i feel like actually understands anything about me",
                            "Okay daddy ill go sleep",
                            "you should get warhammer when your wallet is not crying tears of blood",
                            "Imma tease a dick down your throat. My bad G, that was agressive",
                            "Hermes is SCARY, he's reading me LIKE A BOOK",
                            "Wanna cuddle with me? You are going to get blue balled HARD",
                            "Imma cuddle your ass off",
                            "You can't handle overly affectionous chewy",
                            "You should buy a pishock and gimme the remote",
                            "You have cursed me.. (Chew summons addie into my dms)",
                            "I've been freaky since we've hanged out, i've touched people..",
                            "My worst gooner arc would probably be when I just started and erped with 4 people every other day",
                            "You are hella gay atleast 70-90%",
                            "Mies: Perv, Chew: Said the gooner, Mies: Said the other gooner, Chew: Said the goonerst of them all",
                            "I am now officially legal age to drink in america (Turned 21)",
                            "gotta be a lil gay for the homies",
                            "Fuck you (As you proceed to summon addie into my dms for the THIRD TIME)",
                            "Doing good, thanks for checking up on me you fucker",
                            "enjoy uni life mies who knows you might get a gf",
                            "Damn cuddle slut",
                            "I'm more inclined to bully you if you have ft",
                            "Mies: Hard or hard at work? Chew: Why not both?",
                            "Vroom! (Chew driving while drunk)",
                            "Chew: Was I drunk driving to McDonald's? Mies: YES YOU FUCKER! Chew: Worth it :P",
                            "We can always do the phantom push down a set of stairs",
                            "You replaced me with POE2 ;w;",
                            "Me just lonely cuz a certain person is ill rn",
                            "just dont jerk off before we cuddle xD",
                            "Mies: So im just a convenient teasing bag? Chew: Yes, plus a good friend 2 in 1",
                            "Cuz I feel like shit let's schedule a hangout (Unheard of)",
                            "Gonna kms tomorrow w 3h of sleep",
                            "Imma touch ur e pixels if you want",
                            "My consciousness is about to fuck off",
                            "Can I touch you?",
                            "Eww Instant shit (Instant coffee)",
                            "MERRY CRIMBUS",
                            "Teeny msg me finally on Christmas 😭, She lives!!!",
                            "Missed hanging with you ;w;",
                            "Gut feeling something is gonna happen between you and miko once she moves in with you",
                            "Chew: Can I visit you in the future? Mies: Idk can you? Mr Uk flight ticket",
                            "I feel like the universe is trying to stop me from going to get miko",
                            "You a good gooner",
                            "(Help im backed up af)",
                            "Ur gonna get together with teeny at some point as well",
                            "Holy fucking shit, literally just got kabedoned",
                            "Ive seen you be passed around bucko",
                            "WHY DID I HAVE TO BECOME A FKN BOTTOM",
                            "Dont doubt my memory of random useless stuff",
                            "Im in danger of getting pegged :P",
                            "You eating pickles and coffee, joyous occasion",
                            "She did use my dick as a gearshift while making car noices :3",
                            "You're my emotional support 'fag' Finnish dude",
                            "Consistent prostate checks has never killed anybody",
                            "Video: Fuck you chewy, lemme lick feet",
                            "Imma guak guak 9000 you once i see you in vr next time",
                            "Missed out bigtime as im STILL A FUCKIGN VIRGIN",
                            "I dont snore, you freaking jappy (I indeed did snore)",
                            "My tushy is not for business buddy",
                            "Chew -> Gets banned from vrc",
                            "Chew: U need a dommy mommy voice. Mies: 'Pukes'",
                            "Chew -> Gets banned from vrc AGAIN"};

    QStringList whoSent = {"Mies & Chew 31/3/2025", "Chew 5/4/2025", "Sad Chew 13/4/2025", "Horny Mies 17/4/2025", "Mies 12/5/2025", "Mies & Chew 12/5/2025",
                            "Sad Mies 17/5/2025", "Chew & Mies 19/5/2025", "Traumatised Chew 20/5/2025", "Chew 20/5/2025", "Mies 20/5/2025",
                            "Sentimental Mies 21/5/2025", "Mies 21/5/2025", "Mies & Chew 22/5/2025", "Drunkard Chew 22/5/2025", "Liar Mies 22/5/2025", "Weirded out Mies 22/5/2025",
                            "Fatass Mies & Chew 23/5/2025", "Doubtful Mies 25/5/2025", "Mies boutta commit crime 26/5/2025", "Irresponsible Chew & Mies 26/5/2025",
                            "Chew 27/5/2025", "Mies & Chew 27/5/2025", "Horny Mies 27/5/2025", "Clear headed Chew 27/5/2025", "Teasing Chew 28/5/2025", "Chew 28/5/2025", "Chew 28/5/2025",
                            "Mies 28/5/2025", "Generous Chew 28/5/2025", "EMO Chew 29/5/2025", "Mies 2/6/2025", "Mies 2/6/2025", "Mies 3/6/2025", "Mies 8/6/2025", "Teasing Chew 13/6/2025",
                            "Chew 13/6/2025", "Chew 16/6/2025", "Chew 27/6/2025", "Cocky Chew 27/6/2025", "Horny Chew 27/6/2025", "Chew witch 29/6/2025", "Freaky Chew 2/7/2025",
                            "Horny Chew 3/7/2025", "Chew 8/7/2025", "Gooner Mies & Chew 11/7/2025", "Bday Mies 15/7/2025", "Gay Mies 24/7/2025", "Mies 26/7/2025",
                            "Chew 4/8/2025", "Chew 20/8/2025", "Chew 26/8/2025", "Chew 10/10/2025", "Mies & Chew 15/10/2025", "Drunk Chew 19/10/2025", "Dumb Chew & Mies 20/10/2025",
                            "Chew 20/10/2025", "Sad Chew 20/10/2025", "Lonely Chew 21/10/2025", "Horny Chew 22/10/2025", "Mies & Chew 22/10/2025", "Chew 27/10/2025",
                            "Suicidal Mies 28/10/2025", "Horny Chew 31/10/2025", "Sleepy Chew 10/11/2025", "Chew 13/11/2025", "Mies 24/11/2025", "Mies 25/12/2025", "Chew 27/12/2025",
                            "Chew 27/12/2025", "Chew 28/12/2025", "Chew & Mies 28/12/2025", "Stupid Mies 31/12/2025", "Chew 3/1/2026", "Backed up Mies 9/1/2026", "Mies being right 12/1/2026",
                            "Bissful Mies 13/1/2026", "Chew 29/1/2026", "Mies 29/1/2026", "Smart Mies 29/1/2026", "Ignorant Mies 30/1/2026", "Happy Chew 31/1/2026",
                            "Ignorant Mies 2/2/2026", "Rude Chew 4/2/2026", "Teeny 4/2/2026", "Horny Mies 8/3/2026", "Mies 16/3/2026", "Mies 19/3/2026", "Mies 10/4/2026", "Lying Chew 21/4/2026",
                            "Chew 30/4/2026", "Chew & Mies 16/5/2026", "Chew 19/5/2026"};
    int rand;
    int buffer;
    QStringList pastNumbers = {""};
public slots:
    void buttonHandler();
    void updateConfetti();
    void startConfetti();
protected:
    virtual void paintEvent(QPaintEvent* event) override;
private:
    Ui::message_window *ui;
    MainWindow * pWindow;
    struct confettiList {
        int x, y, width, height, speed = 2;
        QColor color;
    };
    QTimer* timer;
    QVector<confettiList> confettiVect;
};

#endif // MESSAGE_WINDOW_H
