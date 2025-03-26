ticket = self.env['crm.ticket'].browse(ticket_id)
pe = False
for etapa in ticket.etapa_ids:
   if etapa == ticket.etapa_id:
       break
   pe = etapa
if pe: 
    ticket.etapa_id = pe
