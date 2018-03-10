#ifndef CML_ERRNO_H
#error "Never use <cml/errno/message.h> directly; include <cml/errno.h> instead."
#endif

#ifndef CML_ERRNO_MSG_H
#define CML_ERRNO_MSG_H

__CML_BEGIN_DECLS

/* Provide a general messaging service for client use.  Messages can
 * be selectively turned off at compile time by defining an
 * appropriate message mask. Client code which uses the CML_MESSAGE()
 * macro must provide a mask which is or'ed with the CML_MESSAGE_MASK.
 *
 * The messaging service can be completely turned off
 * by defining CML_MESSAGING_OFF.  */

void cml_message(const char * message, const char * file, int line,
                 unsigned int mask);

#ifndef CML_MESSAGE_MASK
        #define CML_MESSAGE_MASK 0xffffffffu /* default all messages allowed */
#endif

extern unsigned int cml_message_mask;

/* Provide some symolic masks for client ease of use. */

enum {
        CML_MESSAGE_MASK_A = 1,
        CML_MESSAGE_MASK_B = 2,
        CML_MESSAGE_MASK_C = 4,
        CML_MESSAGE_MASK_D = 8,
        CML_MESSAGE_MASK_E = 16,
        CML_MESSAGE_MASK_F = 32,
        CML_MESSAGE_MASK_G = 64,
        CML_MESSAGE_MASK_H = 128
};

#ifdef CML_MESSAGING_OFF        /* throw away messages */
        #define CML_MESSAGE(message, mask) do { } while(0)
#else                           /* output all messages */
        #define CML_MESSAGE(message, mask) \
        do { \
                if (mask & CML_MESSAGE_MASK) \
                { \
                        cml_message(message, __FILE__, __LINE__, mask); \
                } \
        } while (0)
#endif

__CML_END_DECLS

#endif
